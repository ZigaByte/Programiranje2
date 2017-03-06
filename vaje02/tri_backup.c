#include<stdio.h>

int main(){
	int m, n;
	scanf("%d %d\n", &m, &n);

	int count = 0;
	int i, j, k;	
	for(i = m; i <= n; i++){
		for(j = 1; j < n; j++){
			int found = 0;
			for(k = 1; k < n; k++){
				if(i * i == j * j + k * k){
					//printf("%d : %d = %d + %d\n",count, i, j, k);			
					count++;				
					found = 1;
					break;				
				}
			}	
			if(found != 0)
				break;
		}	
	}

	printf("%d\n", count);
	
	return 0;	
}
