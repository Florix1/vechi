/*-- testLG.c -- prelucrare lista generica de pointeri la puncte din plan */
#include "tlg.h"
#include <string.h>

//persoana are un nume si un nr de telefon
//telefonul are forma 0701234567 (10 caractere intre 0-9)+ \0.
//primul caracter este '0'
typedef struct {char*nume, telMobil[11];}TPers;


//generez un cod  unic pentru primele 2 caractere din sir (convertite la lowercase)
//aa-> intoarce 0
//ab-> intoarce 1
//ba-> intoarce 25...
int codHashNume(void*a)
{
	char *p=((TPers*)a)->nume;
	return (*p-'a')*('z'-'a')+*(p+1)-'a';
}

int codHashTel(void*a)
{
	char *p=((TPers*)a)->telMobil+2;
	//intoarcem numarul format de cifrele 2-4 ale nr de tel
	//ex 0725195234 => 251
	return (*p-'0')*100+(*(p+1)-'0')*10+*(p+2)-'0';
}

void AfiElPers(void * ae)
{
  TPers *p = (TPers*)ae;
  printf("[%s %s]\n ", p->nume, p->telMobil);
}

void* copie (void* el)
{
	TPers* p=(TPers*)el, *rez;
	rez=malloc(sizeof(TPers));
    if(!rez) return NULL;
	strcpy(rez->telMobil, p->telMobil);
	rez->nume=strdup(p->nume);
    if(!rez->nume) {free(rez);return NULL;}
	return rez;

}

TLG GenerareListaPers(size_t nrPers)
{
	/*citesc in ordine pentru nr pers
		numele - o linie de max 100 caractere
		nr telefon - o linie max 10 caractere+\0
	 */
	int i, succes;
	char buf[100];
	TLG r=NULL;
	TPers p;
	for(i=0;i<nrPers;i++)
	{
		fgets(buf,99, stdin);
		p.nume=strdup(buf);
		p.nume[strlen(p.nume)-1]='\0';
		if(!p.nume)
			return r;
		fgets(buf,99,stdin);
		strncpy(p.telMobil, buf,10);
		p.telMobil[10]='\0';
		succes=InsLG(&r,&p,sizeof(TPers));
		if(!succes)
			return r;
	}
	return r;
}

//functii care compara 2 persoane dupa nume respectiv dupa telefon
int cmpPersNume(void *p1,void*p2)
{
	return strcmp( ((TPers*)p1)->nume,((TPers*)p2)->nume );
}

int cmpPersTel(void *p1,void*p2)
{
	return strcmp( ((TPers*)p1)->telMobil,((TPers*)p2)->telMobil );
}

//functie care elibereaza spatiul alocat pentru o persoana
//este folosita de DistrTH
void elibPers(void * p)
{
	free( ((TPers*)p)->nume);
}

//vom folosi 2 hash-uri
//primul este folosit pentru a indexa numele si ia in calcul primele 2 caractere ale numelui (convertite in prealabil la lowercase)
//al doilea hash este folosit pentru a indexa numerele de telefon si ia in calcul cifrele de pe pozitiile 2-4 (primele 2 presupunem ca sunt 07)

TH* GenerareHash(TLG listaPers,TH**ah2)
{
	TH*h1,*h2;//cele 2 hash-uri generate
	TLG p; 
	int rez1,rez2;
	TPers* copiePers;
	//calcul dimensiuni maxime pt hash-uri
	size_t M1=('z'-'a')*('z'-'a'), M2=1000;
	
	//initializez cele 2 hash-uri cu functiile de hashing aferente
	//tratam erorile de alocare
	h1=(TH*)IniTH(M1,codHashNume);
	if(!h1){ *ah2=NULL; return NULL;}
	
	h2=(TH*) IniTH(M2,codHashTel);
	if(!h2){*ah2=NULL; DistrTH(&h1, elibPers); return NULL;}
	
	//pentru fiecare celula din lista creez o copie a informatiei si o inserez in hash
	//daca alocarea nu reuseste distrug cele 2 hash-uri si intorc NULL;
	for(p=listaPers;p!=NULL;p=p->urm)
	{
		copiePers=copie(p->info);	
		if(!copiePers)
		{
			*ah2=NULL;
			DistrTH(&h1, elibPers);
			DistrTH(&h2, elibPers);
			return NULL;
		}
		rez1=InsTH(h1,copiePers, sizeof(TPers), cmpPersNume);
		copiePers=copie(p->info);
		if(!copiePers)
		{
			*ah2=NULL;
			DistrTH(&h1, elibPers);
			DistrTH(&h2, elibPers);
			return NULL;
		}
		rez2=InsTH(h2,copiePers, sizeof(TPers), cmpPersTel);
		if(!copiePers)
		{
			*ah2=NULL;
			DistrTH(&h1, elibPers);
			DistrTH(&h2, elibPers);
			return NULL;
		}
	}
	*ah2=h2;
	return h1;
}


int main()
{ 
 	TLG x = NULL;
 	TH *h1=NULL, *h2=NULL;
  	//recomand sa aveti un fisier text cu linii
	//nume pers
	//nr telefon

	x = GenerareListaPers(3);
    if(!x)
    {
        printf("Lista nu a putut fi generata\n");
        return 0;
    }
    
  	Afisare(&x, AfiElPers);
    
	h1=GenerareHash(x,&h2);
    printf("tabela hash nume \n");
	AfiTH(h1,AfiElPers);
    
    printf("tabela hash numar telefon \n");
	AfiTH(h2,AfiElPers);
  	
    /* secvente de test */

  
  	Distruge(&x, elibPers);
	DistrTH(&h1, elibPers);
	DistrTH(&h2, elibPers);
  	return 0;
}

