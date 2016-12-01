/*  HATEGAN Florin George - 311CB */
#include "header.h"

void Initializare(ATC x)
{
	*x = (TC)malloc(sizeof(TCelula));
	if (!*x) 
		return ;
	(*x)->urm = NULL;
	(*x)->jos = NULL;
	(*x)->ant = NULL;
	(*x)->litera = 0;
	(*x)->sign = 0;
}



void Show(TC x,void *a,FILE *f) {
	if (!x) return;			
	TC use;
	TC aux = (TC)malloc(sizeof(TCelula));	//initializare celula
			if (!aux) return;	//despartitoare
			aux->jos = NULL;
			aux->urm = NULL;
			aux->ant = NULL;
			aux->sign = ' ';
			aux->litera = ' ';
	IntrQ(a,x);				//introducem prima celul(goala)
	IntrQ(a,aux);				//si celula despartioare
	while ( !VIDA(a) )
	{
		use = (TC)Extrage(a);		//extragem celula
		
		if ( use->litera && use->litera == ' ' ) {
		fprintf(f,"\n");
			if ( !VIDA(a) )		//evitare loop infinit
			IntrQ(a,use);
		} else {  			//afisare
		fprintf(f,"(");
		if (use->sign) 
			fprintf(f,"%c",use->sign);
		fprintf(f,":");
		if (use->litera)
			fprintf(f,"%c",use->litera);
		fprintf(f,")"); 
		 
		if ( use->jos != NULL)
			{
			use = use->jos;
			while (use != NULL)
				{		//introducem toti fii in coada
				IntrQ(a,use);
				use = use->urm;
				} 
			}
		}	
	} 
	
}



void Delete(TC arb,TC ant, char let) {		//parcurgere recursiva
	if (!arb) return;
	if ( arb->litera  && arb->litera == let ) {
		if ( arb->jos == NULL) {	//daca nu are fiu
						//sterge celula in functie de
			if( ant->urm == arb) {	//celula anterioara
				ant->urm = arb->urm;
				free(arb);
				return;
			} else {
				ant->jos = arb->urm;
				free(arb);
				return;
			}
		} else  {		//daca are legaturi sterge litera
			arb->litera = 0;
			return;
			}
	}

	Delete(arb->urm,arb,let);
	Delete(arb->jos,arb,let);
	
	if ( !arb ) return;
	// verificare "frunza"
	if ( !arb->urm && !arb->jos && ant != arb && arb->litera == 0) {
		if( ant->urm == arb) {			//stergere in functie
				ant->urm = arb->urm;	//de legatura anterioara
				free(arb);
				return;
			} else if (ant->jos == arb) {
				ant->jos = arb->urm;
				free(arb);
				return;
			}
	}			
	// verficare nod fara fiu
	if (arb->litera == 0 && !arb->jos && arb->urm ) {
		if( ant->urm == arb) {		//are frati stanga (si dreapta)
				ant->urm = arb->urm;
				free(arb);
				return;
			} else {		//primul fiu al parintelui
				ant->jos = arb->urm;
				free(arb);
				return;
			}
	}
}

void add(TC x,char *sir,char let)
{
	int nr = strlen(sir), i = 0;
	for ( ; i < nr ; i++ ) {
		if ( x->jos == NULL) {	//daca lipseste fiul il creaza
			TC aux = (TC)malloc(sizeof(TCelula));
			if (!aux) return;	
				aux->jos = NULL;
				aux->urm = NULL;
				aux->ant = NULL;
				aux->sign = sir[i];
				aux->litera = 0;
				x->jos = aux;
				x = x->jos;
		} else {	//daca exista fiu cauta codificare pentru nod
			x = x->jos;
			TC y = x;
			while ( y != NULL && (y->sign != sir[i]) ) {
				x = y;
				y = y->urm;
			}
			if ( y == NULL) {	//daca nu exista creeaza celula
				TC aux = (TC)malloc(sizeof(TCelula));
				if (!aux) return;
				aux->jos = NULL;
				aux->urm = NULL;
				aux->ant = NULL;
				aux->sign = sir[i];
				aux->litera = 0;
				x->urm = aux;
				x = x->urm;
			} else {
				x = y;
			}
		}
		if( i == nr-1)			//la final atribuie litera
			x->litera = let;
	}
}

int Search(TC arb,char* sir,char let) {
	arb = arb->jos;			//coboara de pe celula goala
	int nr = strlen(sir) - 1;
	int i = 0;
	for ( ; i <=nr ; i++) {
		while ( arb != NULL && (arb->sign != sir[i]) ) {
		arb = arb->urm;		//verifica toti fratii daca au semnul
		}
		if (!arb) {
			return -1;
		} else { 
			if ( i != nr )		
				arb = arb->jos;  //coboara pe primul fiu
			else 
				if (arb->litera)
					if (arb->litera == let)
						return 0;	
					return -1;
		}		
	}
} 

char Decode(TC arb,char* sir) {	 	//similar search
	arb = arb->jos;			
	int nr = strlen(sir) - 1;
	int i = 0;
	for ( ; i <=nr ; i++) {
		while ( arb != NULL && (arb->sign != sir[i]) ) 
		arb = arb->urm;	
		if (!arb) {
			return 0;
		} else { 
			if ( i != nr )
			 arb = arb->jos;  
			else 
				if (arb->litera)
					return arb->litera;
				else 
					return 0;
		}		
	}
} 









