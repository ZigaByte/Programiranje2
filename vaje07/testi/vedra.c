#include<stdio.h>
#include<stdlib.h>

int korakov(int k, int n, int *prostornina,  int *vedra, int globina){
	if(globina<=0)return 0;

	int i, j; 

	for(i = 0; i < n; i++){
		if(vedra[i] == k) return 1;	
	}

	for(i = 0; i < n; i++){
		if(vedra[i] == prostornina[i])continue;
		int t = vedra[i];		
		vedra[i] = prostornina[i];	
		int da = korakov(k, n, prostornina, vedra, globina-1);	
		if(da)return 1;
		vedra[i] = t;		
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i == j || vedra[i] == 0) continue;
				
			int ti = vedra[i];		
			int tj = vedra[j];
			vedra[j] = vedra[i] + vedra[j];	
			vedra[i] = 0;
			if(vedra[j] > prostornina[j]){
				vedra[i] = vedra[j] - prostornina[j];
				vedra[j] = prostornina[j];
			}

			int da = korakov(k, n, prostornina, vedra, globina-1);	
			if(da)return 1;
			vedra[i] = ti;	
			vedra[j] = tj;	
		}
	}

	for(i = 0; i < n; i++){
		if(vedra[i] == 0)continue;
		int t = vedra[i];
		vedra[i] = 0;		
		int da = korakov(k, n, prostornina, vedra, globina-1);	
		if(da)return 1;
		vedra[i] = t;		
	}
		
	return 0;
}

int main(){
	int n;
	scanf("%d", &n);

	int *vedra = (int*)malloc(sizeof(int) * n);
	int *prostornina = (int*)malloc(sizeof(int) * n);
	int i;	
	for(i = 0; i < n; i++){
		scanf("%d", &prostornina[i]); 	
		vedra[i] = 0;
	}
	int k;
	scanf("%d", &k);
	for(i = 1; i < 100; i++){
		if(korakov(k, n, prostornina, vedra, i)){		
			printf("%d\n", i-1);
			break;
		}
	}
	return 0;
}
