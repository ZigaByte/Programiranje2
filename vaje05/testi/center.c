#include<stdio.h>

int dolzina(char *beseda){
	int d = 0;
	while(beseda[d++] != '\0');
	return d-1;
}

void prepisi(char *beseda, char *vrstica){
	while(*beseda != '\0'){
		*vrstica = *beseda;
		vrstica++;
		beseda++;
	}
	*vrstica = '\0';
}

void izpisiPoravnano(char *vrstica, int n){
	int i = 0;
	for(i = 0; i < (n - dolzina(vrstica))/2; i++){
		printf(" ");
	}
	printf("%s\n", vrstica);
}

int main(){
	int n;
	scanf("%d", &n);

	char beseda[n];
	char vrstica[n];
	vrstica[0] = '\0';

	int prva = 1;	

	while(scanf("%s", beseda) != EOF){
		if(prva){
			prepisi(beseda, vrstica);
			prva = 0;continue;
		}		

		if(dolzina(vrstica) + dolzina(beseda) + 1 <= n){
			int d = dolzina(vrstica);
			vrstica[d] = ' ';
			prepisi(beseda, &vrstica[d+1]);
		}else{
			izpisiPoravnano(vrstica, n);
			prepisi(beseda, vrstica);
		}
	}
	izpisiPoravnano(vrstica, n);

	return 0;

}
