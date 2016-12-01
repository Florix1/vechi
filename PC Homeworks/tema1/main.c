//	Hategan Florin George 321CB, Tema1 PC
#include "functii.c"


int main() {
	
	int loop,i;
	scanf("%d",&loop);
	uint8_t ip1[4],ip2[4],masca[4];
	int check;			// 0/1 tine minte raspunsul la 4
	
	for (i = 1; i <= loop; i++) {
	
		printf("%d\n",i);
		Task01(ip1,masca);
		Task23(ip1,masca);
		Read(ip2,masca);
		check = Check(ip1,masca,ip2);
		Task4(check);
		Task5(ip1,ip2);
		Task6(check,ip2);
		Task7(ip1,ip2);
		Task8(ip1,ip2);
	
	}
	
	return 0;
}
