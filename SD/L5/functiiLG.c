/*--- functiiLG.c -- operatii de baza pentru lista simplu inlantuita generica---*/
#include "tlg.h"

int InsLG(ALG aL, void* ae, size_t d)
{
  TLG aux = malloc(sizeof(TCelulaG));
  if(!aux) return 0;
  aux->info = malloc(d);
  if (!aux->info)          
  { free(aux); return 1;}
  memcpy(aux->info, ae, d);
  aux->urm = *aL;
  *aL = aux;
  return 0;
}

void DistrugeLG(ALG aL) /* eliminare celula si element */
{ 
  TLG aux = *aL;     /* adresa celulei eliminate */
  if (!aux) return; /* lista vida */
  free(aux->info);  /* elib.spatiul ocupat de element*/
  *aL = aux->urm;    /* deconecteaza celula din lista */
  free(aux);   /* elibereaza spatiul ocupat de celula */
}

void Distruge(ALG aL) /* distruge lista */
{
  while(*aL != NULL)
    DistrugeLG(aL);
}

size_t LungimeLG(ALG a)      /* numarul de elemente din lista */
{ 
  size_t lg = 0;
  TLG p = *a;
  for (; p != NULL; p = p->urm) lg++;  /* parcurge lista, numarand celulele */
  return lg;
}

void Afisare(ALG aL, TFAfi afiEL)
{ 
  if(!*aL) { printf("Lista vida\n"); return;}
  printf("Lista: ");
  for(; *aL; aL = &(*aL)->urm)
    afiEL((*aL)->info);
  printf("\n");
}
