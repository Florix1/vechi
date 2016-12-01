#include "inceput.h"

void Initialize(ATS x,char* starei) {

	*x = (TS)malloc(sizeof(TState));
	if(!*x)
		return;
	(*x)->down  = NULL;
	(*x)->right = NULL;
	(*x)->letW = 0;
	(*x)->letR = 0;
	(*x)->move = 0;
	(*x)->state = strdup(starei);
}

void Modify(TS x,char* final) {

	while( strcmp(final, x->state) != 0 )
		x = x->right;
	x->move = 'S';
}

void Add(TS map, char* stare) {

	while( map->right != NULL)
		map = map->right;
	TS aux;
	aux = (TS)malloc(sizeof(TState));
	if(!aux)
		return;
	aux->right = NULL; 
	aux->down = NULL;
	aux->letW = 0;
	aux->letR = 0;
	aux->move = 0;
	aux->state = strdup(stare); 
	map->right = aux;
	aux = NULL;
} 

void Build(TS map,char* crtst,char crtsgn,char* fst,char fsgn,char way) {
	// f -final , crt - current, sng - sign,  st-state
	
	TS cursor = map;
	while ( strcmp(cursor->state, crtst)!= 0 )
		cursor = cursor->right;		
	while ( cursor->down != NULL)
		cursor = cursor->down;
	
	TS aux;
	aux = (TS)malloc(sizeof(TState));
	if (!aux) 
		return; 
	aux->down = NULL;
	aux->letR = crtsgn;
	aux->letW = fsgn;
	aux->move = way;
	aux->state = "";
	while ( strcmp(map->state, fst) != 0)
		map = map->right;
	aux->right = map;
	
	
	cursor->down = aux;
	aux = NULL;
	
} 

void DeleteCel(TS x) {

	if (x != NULL) {
		
	DeleteCel(x->down);
	free(x);
	}

}

void Delete(TS x) {

	if (x != NULL ) { 
		Delete(x->right);
		free(x->state);
		DeleteCel(x);
		
	}
	
}	






