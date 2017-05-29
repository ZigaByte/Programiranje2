#include<stdio.h>
#include<stdlib.h>
#include"kopicoid.h"

int main(){
    kopica* prvotna = NULL;

	int n;
	scanf("%d", &n);
	char* ukaz = (char*)malloc(sizeof(char) * 20);

	int i;
	for(i = 0; i < n; i++){
        scanf("%s", ukaz);
        if(ukaz[0] == 'i'){
            izpisi(prvotna);
            printf("\n"); 
        }
        else if(ukaz[0] == 'o'){
            prvotna = odstrani(prvotna);
        }else{
            kopica* nova = malloc(sizeof(kopica));
            scanf("%d", &(nova->value));

            if(ukaz[0] == 'd'){
                prvotna = dodaj(prvotna, nova);
            }
        }
    }
	return 0;
}
