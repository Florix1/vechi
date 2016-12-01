void Binary(int n, char* space);

int Task0(char* ip, char* buff) {

	char* str;
	strcpy(ip, strtok(buff,"/"));
	str = strtok(NULL,"/");
	printf("-0 %s\n",ip);
	return atoi(str);
}


void Task5(char* ip1,char* ip2) {

	int nr,i;
	printf("-5 ");
	char buff[3];
	strcpy(buff, strtok(ip1,".") );
	nr = atoi(buff);
	printf("%X", nr );
	for (i = 0; i < 3; i++)  {
		printf(".");
		strcpy(buff, strtok(NULL,".") );
		nr = atoi(buff);
		printf("%X", nr );
	}
	printf(" ");
	strcpy(buff, strtok(ip2,".") );
	nr = atoi(buff);
	printf("%o", nr );
	for (i = 0; i < 3; i++)  {
		printf(".");
		strcpy(buff, strtok(NULL,".") );
		nr = atoi(buff);
		printf("%o", nr );
	}
	printf("\n");
}	

void Task7(char* ip1, char* ip2) {

	printf("-7 ");
	int nr,i;
	char buff[3],bin[9];
	strcpy(buff, strtok(ip1,".") );
	nr = atoi(buff);
	Binary(nr, bin);
	for (i = 0; i < 3; i++)  {
		printf(".");
		strcpy(buff, strtok(NULL,".") );
		nr = atoi(buff);
		Binary(nr, bin);
	}
	printf(" ");
	strcpy(buff, strtok(ip2,".") );
	nr = atoi(buff);
	Binary(nr, bin);
	for (i = 0; i < 3; i++)  {
		printf(".");
		strcpy(buff, strtok(NULL,".") );
		nr = atoi(buff);
		Binary(nr, bin);
	}
	printf("\n");
		

}

void Binary(int n, char* space) {
	char *varf = space;
	space[8] = '\0';
	int mask = 256;
	while ( mask >>= 1) {
	if ( (mask & n) == mask )
		*space++ ='1';
		else
		*space++ ='0';
	}
	printf("%s",varf);

}

void Mask(int x,char *masca) {

	uint8_t i = 0,biti;
	for(; i < 4; i++) {
		if ( x > 8 ) {
			biti = 255;
			sprintf(masca + strlen(masca),"%u",biti);
			x -= 8;
		} else {
			biti = 0;
			biti =( (~biti) >> 8-x ) << 8-x;
			sprintf(masca + strlen(masca),"%u",biti);
			x = 0;
		}
	
			int len = strlen(masca);
			if ( i != 3) 
				masca[len] = '.';
			else
				masca[len] = '\0';
		
	
	}
	
}
/*
	int j,mask;
	char buff[18],buff2[18],ip1[16],ip2[16],masca[16] = "";
	scanf("%s%s",buff,ip2);
	mask = Task0(ip1,buff);
	
	strcpy(buff, ip1);
	strcpy(buff2, ip2);
	
	Mask(mask,masca);
	printf("-1 %s\n",masca); 
	
	strcpy(buff, ip1);
	strcpy(buff2, ip2);
	
	Task5(ip1,ip2);
	Task7(buff,buff2);
	*/
	
