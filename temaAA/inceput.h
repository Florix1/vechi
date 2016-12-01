//	Hategan Florin George - 321 CB, Analiza algoritmilor 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct celula {

	char *state;			//numele starii
	char letR;			//caracterul primit de pe banda
	char letW;			//caracterul ce trebuie scris pe banda
	char move;			// R,L,H
	struct celula *down,*right;

} TState, *TS, **ATS;


void Initialize(ATS, char*);			//intializare "tablou"
void Modify(TS, char*);				//particularizeaza stare finala
void Add(TS, char* );				//adauga stare normala
void Build(TS, char*, char, char*, char, char); //adauga tranzitie 
void DeleteCel(TS);				//sterge celulele vertical
void Delete(TS);				//sterge celulele orizontal
