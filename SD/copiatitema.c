
#include "head.h"
TH* InitTH(int M,FHash f)
{
	TH *a=(TH*)calloc(sizeof(TH),1);
	if (!a) 
	{
		return NULL;
	}
	a->v=(TLC*)calloc(M, sizeof(TLC));
	if(!a->v)
	{
		free(a);
		return NULL;
	}
	int i=0;
	for (; i < M; i++)
  	a->v[i] = NULL;
	
	a->M=M;
	a->fh=f;
	return a;
}

void DistrTH(TH* a, TF elib)
{	
	TLC x,y,aux;
	int i=0;
	for( ; i < a->M ; i++)
		{
		x = a->v[i];
		y = x;
			while (x!=NULL)
			{
			aux=y;
			y=y->urm;
			elib(aux->info);
			free(aux);
			}
		}
	free(a);
	a=NULL;
}


void elib(void* a)
{
	TE x;
	x=(TE)(a);
	free(x->key);
	free(x->value);
}

void print(TH*a, TF afisare)
{
	int i=0;
	TLC *p,x;
	for (; i < a->M ; i++)
	{
	*p=a->v[i];
		if(*p){
			x=*p;
			while(x!=NULL)
			{
				afisare(x->info);
				x=x->urm;
			}
		printf("\n");
		}	
	}


}

void afisare(void* a)
{
	TE x;
	x=(TE)(a);
	printf("Copiaza structura afisare %s %s %d",x->key,x->value,x->frecv);
}

void print_list(TH* a, TF afisare,int x)
{
	TLC y,z = ( a->v[x] );
	while (y != z)
		{
		afisare( y->info );
		y = y->urm;
		}
		
}
void remove1(char* key,TH* a,TF elimina)
{
	int x= a->fh(key),ok=0;
	TLC y,z = ( a->v[x] );
	y=y->urm;
	while ( y!=z && ok==0) 
		{
		TE b= (TE)(y->info);
		if( strcmp(b->key,key) == 0)
			{
			elimina(y);
			ok++;
			}
		y=y->urm;
		}
}

void elimina(TLC y)
{
	TLC aux;
	aux=y;
	if( y!= y->urm){
	aux->ant->urm=aux->urm;
	aux->urm->ant=aux->ant;
	y=y->urm; 
	}
	elib(aux->info);
	free (aux->info);
	free(aux);
	y=NULL;
}

TElement* alocare(char* key,char* value)
{
	TElement* aux;
	aux=(TElement*)malloc(sizeof(TElement));
	if (!aux)
		return NULL;
	aux->key=strdup(key);
	aux->value=strdup(value);
	aux->frecv=0;
	return aux;
}

TLC AlocCel(char* key, char* value)
{
  TLC aux = malloc(sizeof(TCelula));
  if(!aux) return NULL;
  aux->info = malloc(sizeof(TElement));
  if (!aux->info)
  { free(aux); return NULL;}
  memcpy(aux->info, alocare(key,value), sizeof(TElement));
  aux->ant=NULL;
  aux->urm=NULL;
  return aux;
}

void insert(char* key,char* value,ALC a)
{

}


int hash_function(char *key)
{
  int i=0,s=0,l = strlen(key);
  for (; i < l; i++) {
    s += key[i];
  }
  return s;
}

int main(){
return 0;
}



