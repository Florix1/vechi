/*--- functiiLG.c -- operatii de baza pentru lista simplu inlantuita generica---*/
#include "tlg.h"

void* ExistaTH(TH* a,void* ae,TFCmp f)
{
TLG p=a->v;
void* el;
while (p) {
	el=p->info;
	if (f(ae,el)
	}
}


int InsLG(ALG aL, void* ae, size_t d)
{
  TLG aux = malloc(sizeof(TCelulaG));
  if(!aux) return 0;
  aux->info = malloc(d);
  if (!aux->info)
  { free(aux); return 0;}
  memcpy(aux->info, ae, d);
  aux->urm = *aL;
  *aL = aux;
  return 1;
}

void DistrugeLG(ALG aL, TF free_elem) /* eliminare celula si element */
{ 
  TLG aux = *aL;     /* adresa celulei eliminate */
  if (!aux) return; /* lista vida */
  free_elem(aux->info);  /* elib.spatiul ocupat de element*/
  *aL = aux->urm;    /* deconecteaza celula din lista */
  free(aux);   /* elibereaza spatiul ocupat de celula */
}

void Distruge(ALG aL, TF free_elem) /* distruge lista */
{
  while(*aL != NULL)
    DistrugeLG(aL, free_elem);
}

size_t LungimeLG(ALG a)      /* numarul de elemente din lista */
{ 
  size_t lg = 0;
  TLG p = *a;
  for (; p != NULL; p = p->urm) lg++;  /* parcurge lista, numarand celulele */
  return lg;
}

void Afisare(ALG aL, TF afiEL)
{ 
  if(!*aL) { printf("Lista vida\n"); return;}
  printf("Lista: ");
  for(; *aL; aL = &(*aL)->urm)
    afiEL((*aL)->info);
  printf("\n");
}


//functii facute la curs
TH* IniTH(size_t M, TFHash fh)
{
	TH*h=(TH*)calloc(sizeof(TH),1);
	if (!h) 
	{	
		printf("eroare alocare hash\n");
		return NULL;
	}
	h->v=(TLG*)calloc(M, sizeof(TLG));
	if(!h->v)
	{
		printf("eroare alocare vector de pointeri TLG in hash\n");
		free(h);
		return NULL;
	}
	h->M=M;
	h->fh=fh;
	return h;
}

void DistrTH(TH** ah, TF fe)
{
	TLG*p,el,aux;

	//am folosit parcurgere cu pointeri ca sa o aveti si pe aceasta
	for (p=(*ah)->v;p<(*ah)->v+(*ah)->M;p++)
	{
//daca exista elemente corespunzatoare acestui hash
//eliberam info din celula si apoi eliberam celula
			for(el=*p;el!=NULL;)
			{
				aux=el;
				el=el->urm;
				fe(aux->info);
				free(aux);	
			}	
			
	}
	free((*ah)->v);
	free(*ah);
	*ah=NULL;		
}

void AfiTH(TH*ah, TF afiEl)
{
	TLG*p, el;
	for(p=ah->v; p<ah->v+ah->M;p++)
	{
		if(*p)
		{
			printf("%d: ",p-ah->v);
			for(el=*p;el!=NULL;el=el->urm)
				afiEl(el->info);
			printf("\n");
		}
	}

}

//daca elementul exista intoarcem 0
//altfel incercam sa-l inseram si intoarcem rezultatul inserarii
int InsTH(TH*a,void*ae, size_t d, TFCmp f)
{
	int cod=a->fh(ae), rez;
	TLG el;
    
	for(el=a->v[cod];el!=NULL; el=el->urm)
	{
		if(!f(el->info, ae))
			return 0;	
	}
	rez=InsLG(a->v+cod,ae,d); //reminder: a->v+cod <=> &a->v[cod]
	return rez;	
}

