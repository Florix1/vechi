//--------------------FUNCTII TABELA HASH---------------------------------------------------
#include "head.h"

//---------------------Liste circulare generice---------------------------------------------

//#include "head.h"

int cmp(int fcv,char* key,void* a)
{
	TE x=(TE)a;
	if (fcv != x->frecv)
	{
	return (fcv-x->frecv);
	}
	else
	if (strcmp(key,x->key) < 0 )
	return 1;
	return -1;
}

void elib(void* a)
{
	TE x;
	x=(TE)(a);
	free(x->key);
	free(x->value);
}


void elimina(ALC y)
{
	TLC aux;
	aux=*y;
	if( *y != aux->urm){
	aux->urm->ant=aux->ant;
	aux->ant->urm=aux->urm;
	*y=(*y)->urm; 
	}
	else
	*y=NULL;
	elib(aux->info);
	free(aux->info);
	free(aux);

}

TElement* alocare(char* key,char* value,int fcv)
{
	TElement* aux;
	aux=(TElement*)malloc(sizeof(TElement));
	if (!aux)
		return NULL;
	aux->key=strdup(key);
	aux->value=strdup(value);
	aux->frecv=fcv;
	return aux;
}

int AlocCel(char* key, char* value,int fcv,ALC x)
{
  TLC p,aux = malloc(sizeof(TCelula));
  if(!aux) return 0;
  aux->info = malloc(sizeof(TElement));
  if (!aux->info)
  { free(aux); return 0;}
  memcpy(aux->info, alocare(key,value,fcv), sizeof(TElement));
  if ( nrelem(x) != 0)
  {
  p=*x;
  if (cmp(fcv,key,p->info)< 0)
  {
  p=p->urm;
  while(p != *x)
  	{
  	if (cmp(fcv,key,p->info)> 0)
  	break;
  	p=p->urm;
  	}
  }
  aux->urm=p;
  aux->ant=p->ant;
  p->ant->urm=aux;
  p->ant=aux;
  if ( cmp(fcv,key,p->info) > 0 && p==*x)
   *x=aux;
  }
  else
  {
  aux->ant=aux;
  aux->urm=aux;
  *x=aux;
  }
  
  return 0;
}

/*int AlocPTR(void *inf,ALC x)
{
  TLC p,aux = malloc(sizeof(TCelula));
  if(!aux) return 0;
  aux->info = malloc(sizeof(TElement));
  //parte schimbata
  char* key,value;
  int fcv;
  TE r=(TE)inf;
  key=r->key;
  value=r->value;
  fcv=r->frecv;
  //
  if (!aux->info)
  { free(aux); return 0;}
  memcpy(aux->info, alocare(key,value,fcv), sizeof(TElement));
  if ( nrelem(x) != 0)
  {
  p=*x;
  if (cmp(fcv,key,p->info)< 0)
  {
  p=p->urm;
  while(p != *x)
  	{
  	if (cmp(fcv,key,p->info)> 0)
  	break;
  	p=p->urm;
  	}
  }
  aux->urm=p;
  aux->ant=p->ant;
  p->ant->urm=aux;
  p->ant=aux;
  if ( cmp(fcv,key,p->info) > 0 && p==*x)
   *x=aux;
  }
  else
  {
  aux->ant=aux;
  aux->urm=aux;
  *x=aux;
  }
  
  return 0;
}
*/



void afisare(void* a,FILE* f)
{
	TE x;
	x=(TE)(a);
	fprintf(f," (%s)",x->value);
}


int nrelem(ALC a)
{
	int s = 0;
	TLC p = *a;
	if( p == NULL)
		return 0;
	else
		p=p->urm;
		s++;
		while (p!= *a)
		{
		s++;
		p=p->urm;
		}
	return s;
}

int verif1(char *key,TLC a)
{
	if ( a!= NULL )
		{
		TLC b=a->urm;
		TE x=(TE)a->info;
		if ( strcmp(x->key,key) == 0)
		return 1;
		for (; b != a;b=b->urm)
		{
		TE x=(TE)b->info;
		if ( strcmp(x->key,key) == 0)
		return 1;
		}
		}
	return 0;
}

void printlist(TLC a,FILE *f)
{
	TLC y = a;
	if ( a != NULL)
		{
		afisare( y->info, f );
		y=y->urm;
		}
	while (y != a)
		{
		afisare( y->info, f );
		y = y->urm;
		}
}

/*int main()
{
TLC z,x=NULL;
	printf("Numar de elemente: %d\n",nrelem(&x));
 AlocCel("unu","ceva",10,&x);
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 AlocCel("doi2222","drunk",5,&x);
	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 AlocCel("treeeeeeeei","b",9,&x);
	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 AlocCel("ppppaaattttrrruuu","a",9,&x);
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 AlocCel("5","sadas",7,&x);
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 	elimina(&(x));
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 	AlocCel("lol","sasdsas",30,&x);
 	z=x->urm;
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 	elimina(&(z));
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 	elimina(&(z));
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 	elimina(&(z));
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 	elimina(&(x));
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 	elimina(&(x));
 	printf("Numar de elemente: %d\n",nrelem(&x));
 	printlist(x);
 	
return 0;
}*/



















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

void DistrTH(TH* a)
{	
	TLC x;
	int i=0;
	for( ; i < a->M ; i++)
		{
		x = a->v[i];
		int j = 1,nr = nrelem(&x);
		for( ; j <= nr; j++)
		elimina(&x);
		}
	free(a);
	a=NULL;
}


int hash_function(char *key)
{
  int i=0,sum=0;
  int l = strlen(key);
  for (; i < l; i++) {
    sum += key[i];
  }
  return sum;
}

void print_list(TH* a,int x,FILE *f)
{
	
	if ( x <= a->M )
	{
	fprintf(f,"%d:",x);
	TLC y =  a->v[x];
	TLC z = y;
	if (y != NULL){
	afisare(y->info,f);
	y=y->urm;
	while (y != z)
		{
		afisare( y->info, f );
		y = y->urm;
		}  
		       }
		       else
		       fprintf(f,"VIDA\n");
		       
	}
}

void print(TH*a,FILE *f)
{
	int i=0;
	for (; i < a->M ; i++)
	{
		printlist(a->v[i],f);
		fprintf(f,"\n");
		
	}	


}


void remove1(char* key,TH* a,int* nr)
{
	int buck = a->fh(key) % (a->M);
	TLC x =  a->v[buck] ;
	if (verif1(key,x) != 0) 
		{
			TE aux=(TE)(x->info);
			while( strcmp(key,aux->key) != 0)
			{
			x=x->urm;
			aux=(TE)(x->info);
			}
			*nr-=1;
			if (x == a->v[buck])
			a->v[buck]=x->urm;
			if( nrelem(&(a->v[buck])) == 1)
			a->v[buck]=NULL;
			elimina(&x);
			
		
		}
}

char* get(char* key,TH* a)
{
	int p=0,buck= a->fh(key) % (a->M);
	TLC x=a->v[buck];
		if (verif1(key,x) != 0) 
		{
		
			TE muta=(TE)(x->info);
			while( strcmp(key,muta->key) != 0)
			{
			
			x=x->urm;
			muta=(TE)(x->info);
			printf("LOOP");
			}
			
		muta=(TE)(x->info);
		char *key1,*value1;
		int fcv1;
		fcv1 = muta->frecv+1;
		key1=strdup(key);
		value1=strdup(muta->value);
		remove1(key,a,&p);
		AlocCel(key1,value1,fcv1,&(a->v[buck]));
		return value1;
		}
		return NULL;
}


int set(char* key,char* value,TH* a,int* nr)
{
int buck= a->fh(key) % (a->M);
TLC x=a->v[buck];
	if (verif1(key,x) == 0)
	{
		if( nrelem(&x) < a->M )
		{
			if ( (*nr + 1) > (2 * a->M) )
			{
			TH *b = InitTH(2 * a->M,a->fh);
			int i=0;
			//verificare
				for (; i<a->M;i++)
				{
				TLC y=a->v[i];
				int j=1;
					for (; j<=nrelem(&y);j++)
					{
					char *key1,*value1;
  					int fcv1;
 					TE r=(TE)y->info;
 					key1=r->key;
 					value1=r->value;
 					fcv1=r->frecv;
 					int buck1=b->fh(key1) % (b->M);
 					AlocCel(key1,value1,fcv1,&(b->v[buck1]));
					y=y->urm;
					} 
				}
			*nr += 1;
			//DistrTH(a);
			*a=*b;
			}
			else
			{
			AlocCel(key,value,0,&(a->v[buck]));
			*nr += 1;
			}
		}
		else
		{
		x=x->ant;
		elimina(&x);
		AlocCel(key,value,0,&(a->v[buck]));
		}
	}


}


int main( int argc,char *argv[] )
{
/*int x=0;
TH *a=InitTH(3,hash_function);
set("a","Merge! :D\n",a,&x);
set("b","234",a,&x);
set("c","123124",a,&x);
set("d","123",a,&x);
set("e","123",a,&x);
set("f","123",a,&x);
set("k","123",a,&x);
print(a);
set("p","123",a,&x);
remove1("b",a,&x);
//set("u","123",a,&x);
//set("C","123",a,&x);
//set("H","000",a,&x);
set("I","000",a,&x);
set("lol","ceva",a,&x);
remove1("a",a,&x);
remove1("d",a,&x);
//remove1("d",a,&x);
get("f",a);
get("lol",a);
get("f",a);
//get("lol",a);
printf("Numarul de elemente:%d\n",x);
print(a);
DistrTH(a);
*/

TH *a=InitTH((int)argv[1],hash_function);
int nr=0;
FILE *fp;
FILE *f;
f  = fopen(argv[3],"w");
fp = fopen(argv[2],"r");
char buffer[100],*str;
	while( fgets(buffer,100, fp) )
	{
	str = strtok ( buffer, " \n");
	printf("%s ",str);
		if (strcmp("set",str) == 0) {
			char *x,*y;
			y = strtok(NULL," \n");
			x = strtok(NULL," \n");
			set(y,x,a,&nr);
			}
		if (strcmp("get",str) == 0) {
			char *x,*y;
			x = strtok(NULL," \n");
			y=get(x,a);
			fprintf(f,"%s\n",y);
			}
		if(strcmp("print",str) == 0){
			print(a,f);
			}
	//	if(strcmp ("print_list",str) == 0 ){
	//		char *x;
	//		x = strtok(NULL," \n");
	//		print_list(a,(int)x,f);
	//		}
		if ( strcmp("remove",str) == 0 )
		{	
			char *x;
			x = strtok(NULL," \n");
			remove1(x,a,&nr);
		}
	}
fclose(fp);
fclose(f);

return 0;
}





















