//	Hategan Florin George 321CB, Tema1 PC
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"

void Show(uint8_t *ip) {

	int i = 0;
	for (; i < 4; i++) {
	
		printf("%d", ip[i]);
		if (i != 3)
			printf(".");
		else
			printf("\n");
	}
} 

void Mask(int x,uint8_t* masc) {

	uint8_t i = 0,biti;
	for(; i < 4; i++){
	
		if ( x > 8 ) {
		
			masc[i] = (uint8_t)255;
			x -= 8;
			
		} else {			//nu foarte optim dar eficient
		
			biti = 0;
			biti =( (~biti) >> (8-x) ) << (8-x);	
				//neredudant pune x de 1 la stanga octetului
			masc[i] = (uint8_t)biti;
			x = 0;
		}
	
	
	}
	
}

void Read(uint8_t* ip1,uint8_t* masca) {
	
	
	char str[16] = "",*p,buffer[18] ="";
	scanf("%s",buffer);
	strcpy(str, strtok(buffer,"/"));
	p = strtok(NULL,"/");			//despartim masca de ip
	if ( p != NULL ) {
		Mask(atoi(p), masca);
	} 
	
	p = strtok(str,".");
	ip1[0] = atoi(p);
	int i;
	for (i = 1; i < 4; i++)  {		//punem octetii intr-un vector
	
		p = strtok(NULL,".");
		ip1[i] = (uint8_t)atoi(p);
	}

	
	
}

void Task01(uint8_t* ip1,uint8_t* masca) {

	Read(ip1,masca);
	printf("-0 ");
	Show(ip1);
	printf("-1 ");
	Show(masca);	
	
}

void Task23(uint8_t* ip1,uint8_t* masca) {

	printf("-2 ");
	uint8_t number;
	int i = 0;
	for(; i < 4; i++) {
					//si pe biti pentru fiecare byte
		number = ip1[i] & masca[i];	
		printf("%u",number);
		if (i != 3)
				printf(".");
			else
				printf("\n");
	}
	
	printf("-3 ");
	for(i = 0 ; i < 4; i++) {
					//sau pe biti pentru fiecare byte
		number = ip1[i] | ( ~masca[i] );
		printf("%u",number);
		if (i != 3)
				printf(".");
			else
				printf("\n");
	}

}

int Check(uint8_t* ip1,uint8_t* masca,uint8_t* ip2) {

	int i = 0,same = 1;
	for(; i < 3; i++) {
	
		if ( ( masca[i] & ip1[i] ) != ( masca[i] & ip2[i] ) ) {
			// verifica bit cu bit pe baza mastii
			same = 0;
			break;
		}
		
	}
	
	return same;	//intoarce 0/1 ==> nu sunt /sunt la fel
}

void Task4(int check) {

	printf("-4 ");
	if (check) 
		printf("da");
	else
		printf("nu");
	printf("\n");

}

void Task5(uint8_t* ip1,uint8_t* ip2) {
	
	printf("-5 ");
	int i;
	for ( i = 0; i < 4; i++) {
	
		printf("%X",ip1[i]);	// #loveprintf
		if (i != 3)
			printf(".");
		else
			printf(" ");
	}	
	
	for ( i = 0; i < 4; i++) {
	
		printf("%o",ip2[i]);	
		if (i != 3)
			printf(".");
		else
			printf("\n");
	}

}

void Task6(int check,uint8_t* ip2) {

	int count,i;
	char empty[18];
	scanf("%d",&count);
	if( check ) {
	
		printf("-6 0");
		for (i = 0; i < count; i++) { 
						//citeste in gol
			scanf("%s",empty);
		
		} 
		
	} else { 
	
		uint8_t masca[4],buff[4];
		printf("-6");
		for (i = 0; i < count; i++) {
		
			Read(buff, masca);
			if ( Check(buff, masca, ip2) ) {
			
				printf(" %d",i+1);
			} 
			
			
		}
	
	}
	
	printf("\n");

}

void Binary(uint8_t ip) {
	
	int mask = 256;		//in conditie in while se shifteaza  ==> 128
	while( mask >>= 1) {
				//verificare bit cu bit 
		if (mask == (ip & mask) )
			printf("1");
		else
			printf("0");
	
	}

}

void Task7(uint8_t* ip1,uint8_t* ip2) {

	int i;
	printf("-7 ");
	for(i = 0; i < 4; i++) {
	
		Binary(ip1[i]);
		if (i != 3)
			printf(".");
		else
			printf(" ");
	}
	
	for(i = 0; i < 4; i++) {
	
		Binary(ip2[i]);
		if (i != 3)
			printf(".");
		else
			printf("\n");	
	}
	
}

void Task8(uint8_t* ip1,uint8_t* ip2) {

	char letter = '\0';
	int cat,rest,i;
	printf("-8 ");
	for( i = 0; i < 4; i++) {
	
		cat = ip1[i] / 32;	
		rest = ip1[i] % 32;
					//salvam catul si restul
		if ( cat ) 
			printf("%d",cat);
	
		if ( rest <= 9) {
	
			printf("%d",rest);
		
		} else {
	
			rest -= 9;
			letter = 'A' + rest - 1;  //incrementam ascii 
					// 'A'-1 better than '@'	
			printf("%c",letter);
		}
		
		
		if (i != 3)
			printf(".");
		else
			printf(" ");
		
	
	} 
	
	for( i = 0; i < 4; i++) {
	
		cat = ip2[i] / 32;
		rest = ip2[i] % 32;
	
		if ( cat ) 
			printf("%d",cat);
	
		if ( rest <= 9) {
	
			printf("%d",rest);
		
		} else {
	
			rest -= 9;
			letter = 'A' + rest - 1;
			printf("%c",letter);
		}
		
		if (i != 3)
			printf(".");
		else
			printf("\n");
		
	
	}

}



