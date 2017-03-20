#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int zaporedje[n];

	int i, d;
	for(i = 0; i < n; i++){
		scanf("%d", &zaporedje[i]);
	} 

	long long mi = 0, md = 1, max = zaporedje[0];
	
	for(i = 0; i < n; i++){
		if(zaporedje[i] < 0 && zaporedje[i] < max)
			continue;

		if(i >= 1 && zaporedje[i-1] > 0  && zaporedje[i] > 0)
			continue;

		long long vsota = 0;
		for(d = 1; i + d <= n; d++){
			vsota += zaporedje[i + (d-1)];
			if(vsota < zaporedje[i + (d-1)])
				break;

			if(vsota > max){
				mi = i;
				md = d;
				max = vsota;
			}
		} 
	} 
	printf("%lld %lld %lld\n", mi, md, max);
}
