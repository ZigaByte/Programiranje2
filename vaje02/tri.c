#include<stdio.h>
#include<math.h>

int main(){
	int m, n;
	scanf("%d %d\n", &m, &n);

	int count = 0;
	int i, j, k;	
	for(i = m; i <= n; i++){

		for(j = 1; j < i; j++){
			double x = sqrt(i * i - j * j);
			k = (int) x;
			if(i * i == k * k + j * j ){
				count++;				
				break;				
			}
		}	
	}

	printf("%d\n", count);
	
	return 0;	
}
