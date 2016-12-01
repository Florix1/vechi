#include "stdio.h"
#include "stdlib.h"

int main() {

	int c;
	scanf("%d",&c);
	
	while ( c != 0 ) {
		switch(c){
			
			case 1:
				printf("Hello!\n");
				break;
			case 2:
				printf("Bye Bye!\n");
				break;
		}
	scanf("%d",&c);
	}
	
	return 0;
}
