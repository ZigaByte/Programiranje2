#include<stdio.h>
#include<stdlib.h>
#include"kopicoid.h"

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

