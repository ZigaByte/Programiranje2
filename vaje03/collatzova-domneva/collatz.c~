#include<stdio.h>

int n;

long long dolzina(long long i, int stevila[]){
	if(i == 1)
		return 1;

	if(i < n){
		if(stevila[i-1] != 0){
			return stevila[i-1];
		}
	}

	if(i % 2 == 0){
		int d = dolzina(i / 2, stevila) + 1;
		if(i < n){
			stevila[i-1] = d;
		}
		return d;	
	}else{
		int d = dolzina(3 * i + 1, stevila) + 1;
		if(i < n){
			stevila[i-1] = d;
		}
		return d;	
	}
}

int main(){
	scanf("%d", &n);
	
	int najdaljse = 1;
	int najdaljsaDolzina = 1;
	int i;
	int stevila[n];
	stevila[0] = 1;
	for(i = 1; i < n; i++){
		stevila[i] = 0;	
	}

	for(i = 1; i <= n; i++){
		int d = dolzina(i, stevila);
		stevila[i-1] == d;

		if(d > najdaljsaDolzina){
			najdaljse = i;
			najdaljsaDolzina = d;		
		}
	}

	printf("%d %d\n", najdaljse, najdaljsaDolzina);


	return 0;
}
