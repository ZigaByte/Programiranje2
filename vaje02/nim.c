#include<stdio.h>
#include<stdlib.h>

int main(){

	int s, k, n;
	scanf("%d\n%d%d", &s, &k, &n);

	srand(s);

	int vhod = 0;
	while(n > 0){
		scanf("%d", &vhod);
		printf("%d - %d = %d\n", n, vhod, (n-vhod) < 0 ? 0 : (n-vhod));
		n -= vhod;
		if(n <= 0){
			printf("IGRALEC\n");		
			break;
		}

		vhod = rand() % k + 1;
		printf("%d - %d = %d\n", n, vhod, (n-vhod) < 0 ? 0 : (n-vhod));
		n -= vhod;
		if(n <= 0){
			printf("RACUNALNIK\n");		
			break;		
		}
	}

	return 0;
}
