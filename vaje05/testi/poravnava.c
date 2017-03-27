#include<stdio.h>
#include<stdlib.h>

int main(){

	int n;
	scanf("%d", &n);

	char* besedilo = malloc(100000 * sizeof(char));
	char* popravljeno = malloc(100000 * sizeof(char));
	
	char c = getc(stdin);	
	int i = 0;
	while((c = getc(stdin)) != EOF) {
		besedilo[i++] = c;
	}
	//printf("%s", besedilo);

	i = 0;
	int j = 0;
	int first = 1;
	int previous = 0;
	while((c = besedilo[i++]) != '\0'){
		if(c == ' ' || c == '\n' || c == '\t'){
			previous = 1;
			if(first && j != 0){
				first = 0;
				popravljeno[j++] = ' ';	
			}		
		}else{
			first = 1;
			previous = 0;
			popravljeno[j++] = c;		
		}
	}
	popravljeno[j] = '\0';		

	i = 0;
	int bmin = 0;
	int bmax;
	while(1){
		if(i != 0)		printf("\n");
		int f = 0;
		for(i = bmin; i < bmin+n; i++){
			if(popravljeno[i] == '\0'){
				bmax = i;		
				f = 1;			
			}
		}

		for(i = bmin + n; i >= bmin; i--){
			if(popravljeno[i] == ' '){
				if((f == 1 && i <= bmax) || f == 0){
					bmax = i;	
					break;					
				}
			}
		}		

		if(bmax >= j)bmax = j-1;
		int d = bmax - bmin;
		int p = (n - d) / 2;

		for(i = 0; i < p; i++){
			printf(" ");
		}
		for(i = bmin; i < bmax; i++){
			printf("%c", popravljeno[i]);
		}


		bmin = bmax+1;
		if(f) break;
	}

	return 0;
}
