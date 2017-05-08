#include<stdio.h>

int main(){
	int u, i, j;
	scanf("%d", &u);
	int ukazi[u][2];

	for(i = 0; i < u; i++){
		scanf("%d %d", &(ukazi[i][0]), &(ukazi[i][1]));
	}

	for(i = 1; i < u; i++){
		j = i;
		while(j > 0 && (ukazi[j][0] < ukazi[j-1][0] || (ukazi[j][0] == ukazi[j-1][0] && ukazi[j][1] < ukazi[j-1][1]))){
			int temp = ukazi[j][0];
			ukazi[j][0] = ukazi[j-1][0];
			ukazi[j-1][0] = temp;

			temp = ukazi[j][1];
			ukazi[j][1] = ukazi[j-1][1];
			ukazi[j-1][1] = temp;
			j--;
		}
	}

	int trenutna = 0, vagon = 0;
	for(i = 0; i < u;){
		if(ukazi[i][0] != trenutna){
			printf("%d:", ukazi[i][0]);
			trenutna = ukazi[i][0];

			do{
				if(ukazi[i][1] != vagon)
					printf(" %d", ukazi[i][1]);			
				vagon = ukazi[i][1];				
				i++;
			}while(ukazi[i][0] == trenutna);
			vagon = 0;			
			printf("\n");
		}
	}
}
