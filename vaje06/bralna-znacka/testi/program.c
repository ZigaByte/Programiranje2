#include<stdio.h>

void razvrsti(int n, char** imena, int tocke[]){
	int i;	
	for(i = 1; i < n; i++){
		int j = i;
		while(j > 0 && tocke[j-1] < tocke[j]){
			char* temp = imena[j];
			imena[j] = imena[j-1];
			imena[j-1] = temp;

			int tempt = tocke[j];
			tocke[j] = tocke[j-1];
			tocke[j-1] = tempt;
			j--;
		}
	}
}

int izpisi(int m, int n, char** imena, int tocke[]){
	int t = tocke[m];
	int i = m;	
	while(i < n && tocke[i] == t){
		printf("%d. %s (%d)\n", (m+1), imena[i], tocke[i]);
		i++;
	}
	return i-m;
}

int main(){

	int n, k;
	scanf("%d %d", &n, &k);

	char **imena = (char**) malloc(n * sizeof(char*));
	int i;	
	for(i = 0; i < n; i++){
		imena[i] = (char*) malloc(17 * sizeof(char));
		scanf("%s", imena[i]);		
	}

	int tocke[n];
	for(i = 0; i < n; i++){
		scanf("%d", &tocke[i]);		
	}

	razvrsti(n, imena, tocke);

	i = 0;
	while(i < k){
		int izpisanih = izpisi(i, n, imena, tocke);
		i+= izpisanih;

		if(izpisanih == 0)break;
	}

	return 0;
}
