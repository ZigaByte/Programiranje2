#include<stdio.h>
#include<stdlib.h>

typedef struct kopica{
	int value;
	struct kopica* left;
	struct kopica* right;
} kopica;

void izpisi(kopica* k){
    if(k == NULL){ 
        printf("/");
        return;
    }
    printf("%d[", k->value);
    izpisi(k->left);
    printf(", ");
    izpisi(k->right);
    printf("]"); 
}

kopica* dodaj(kopica* a, kopica* b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    if(a->value > b->value) 
        return dodaj(b, a);
    
    kopica* t = malloc(sizeof(kopica));   
    t = a->right; 
    a->right = a->left;
    a->left = dodaj(t, b);
        
    return a;
}

kopica* odstrani(kopica* a){
    if(a == NULL)
        return NULL;        
    return dodaj(a->left, a->right);
}

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
