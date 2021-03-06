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
	free (aux->info);
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



void afisare(void* a)
{
	TE x;
	x=(TE)(a);
	printf("Copiaza structura afisare %s %s %d\n",x->key,x->value,x->frecv);
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

void printlist(TLC a)
{
	TLC y = a;
	if ( a != NULL)
		{
		afisare( y->info );
		y=y->urm;
		}
	while (y != a)
		{
		afisare( y->info );
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


















