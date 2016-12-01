//	Hategan Florin George - 321 CB, Analiza algoritmilor 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct celula {

	char *state;	
	char letR;			//caracterul primit de pe banda
	char letW;			//caracterul ce trebuie scris pe banda
	char move;			// R,L,H
	struct celula *down,*right;

} TState, *TS, **ATS;


void Initialize(ATS,char* );
void Modify(TS ,char* );
void Add(TS ,char* );
void Build(TS,char*,char,char*,char,char);
