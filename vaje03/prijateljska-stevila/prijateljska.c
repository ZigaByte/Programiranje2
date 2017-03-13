#include<stdio.h>

int vsotaDeliteljev(int n){
	int vsota = 0;
	int j;
	for(j = 1; j < n; j++){
		if(n % j == 0){
			vsota += j;
		}
	}
	return vsota;
}

int main(){
	int n;

	scanf("%d", &n);

	int vsota1 = vsotaDeliteljev(n);
	if(n == vsotaDeliteljev(vsota1)){
		printf("%d\n", vsota1);
	}
	else{
		printf("NIMA\n");
	}
	return 0;
}
