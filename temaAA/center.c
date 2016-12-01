#include "inceput.h"

int main () {
	
	FILE *f1;
	f1 = fopen("tape.in", "r");
	char tape[2000];
	if (!fscanf(f1, "%s", tape))
		return -1;
	char* cursor = &( tape[1] );		//initializare cursor
	
	FILE *f2;
	f2 = fopen("tm.in", "r");
	char buffer[20000];
	TS map;
	 	 
	fscanf(f2, "%s", buffer); 
	int i,count,stari;
	stari = atoi(buffer);
	for( i = 0; i < stari; i++) {		//construirea starilor
	
		fscanf(f2, "%s", buffer);
		if ( i == 0)
			Initialize(&map,buffer);
		else
			Add(map,buffer);  
	}
	
	fscanf(f2, "%s", buffer);
	count = atoi(buffer);		
	for ( i = 0; i < count; i++) {		//particularizare stari finale
	
		fscanf(f2, "%s", buffer);
		Modify(map,buffer);
		
	}
	
	char* start;
	fscanf(f2, "%s", buffer);
	start = strdup(buffer);			//initializare stare initiala
	
	fscanf(f2, "%s", buffer);
	count = atoi(buffer);
	char iSign,fSign,way;
	char *iState,*fState;
	for( i = 0; i < count; i++) {		//preluare date tranzitii
	
		fscanf(f2, "%s", buffer);
		iState = strdup(buffer);
		fgetc(f2);
		iSign = (char)fgetc(f2);
		
		fscanf(f2, "%s", buffer);
		fState = strdup(buffer);
		fgetc(f2);
		fSign = (char)fgetc(f2);
		
		fgetc(f2);
		way = (char)fgetc(f2);
		Build(map,iState,iSign,fState,fSign,way);
	}
	
	FILE *f3;
	f3 = fopen("tape.out", "w");
	TS tran = map;
	char input = 0;
	while ( strcmp(tran->state, start) != 0) {
		tran = tran->right;
	}
	
	while (1) {
		
		input = *cursor;
		if ( tran->down == NULL ) {
		
			if( tran->move == 'S') {    //verificare stare finala
				break;
					
			} else {
			
				fprintf(f3,"Se agata!");
				return 1;
			}
			
		}
		
		input = *cursor;
		while ( tran->letR != input ) {
			
			if ( tran->down == NULL) {	//verificare tranzitie
			
				fprintf(f3,"Se agata!");
				return 0;
			} 
				tran = tran->down;
		}
		
		*cursor = tran->letW;
		if ( tran->move != 'H') {
			if ( tran->move == 'R')		//mutare cursor
				cursor++;
			else
				cursor--; 
		} else {
			
			if ( (tran->right)->move != 'S') {
			
				fprintf(f3,"Se agata!");
				return 0;
			}
			
		}
		
		tran = tran->right;
	
	}	


	fprintf(f3, "%s", tape);

	Delete(map);	
		
			
	fclose(f3);
	fclose(f2);
	fclose(f1);		
	return 0;
}
