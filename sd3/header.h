/*  HATEGAN Florin George - 311CB */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct celula
{
	char sign;
	char litera;
	struct celula *ant,*urm,*jos;	
} TCelula, *TC, **ATC;

typedef struct coada 
{
	size_t dime;
	TC ic,sc;
}  TCoada, *AQ;

#define IC(x)	(((AQ)(x))->ic)
#define SC(x)	(((AQ)(x))->sc)

#define VIDA(x)		( IC(x) == NULL && SC(x) == NULL)
#define SINGLE(x)	( IC(x) == SC(x) )

void* InitQ(size_t dime);
TC Extrage(void *a);
void IntrQ(void *a,TC cel);
void Show(TC x,void *a,FILE *f);
void Initializare(ATC x);
void Delete(TC arb,TC ant, char let);
void add(TC x,char *sir,char let);
char Decode(TC arb,char* sir);
