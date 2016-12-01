/*  HATEGAN Florin George - 311CB */
#include "header.h"

void* InitQ(size_t dime) 			//initializare coada
{
	AQ a = (AQ)malloc(dime);
	a->dime = dime;
	a->ic = NULL;
	a->sc = NULL;
	return (void*)a;
}

TC Extrage(void *a)				//extragere element din coada
{
	if (VIDA(a))
		return NULL;
	TC p = IC(a);
	if ( IC(a) == SC(a) )
		SC(a) = NULL;
	IC(a) = IC(a)->ant;
	p->ant = NULL;
		return p;
}

void IntrQ(void *a,TC cel)			//introducere element in coada
{
	if (VIDA(a)) {
		IC(a) = cel;
		SC(a) = cel;
		SC(a)->ant = NULL;
	} else {
		SC(a)->ant = cel;
		SC(a) = SC(a)->ant;
		SC(a)->ant = NULL;
	}
}
