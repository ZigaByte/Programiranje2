#include<stdio.h>
#include<stdlib.h>

typedef struct beseda{
	char* text;
	int frekvenca;
}beseda;

beseda preberiBesedo(){
	beseda b;
	b.text = malloc(sizeof(char) * 100);
	b.frekvenca = 1;	
	int scan = scanf("%s", b.text);
	if(scan == EOF){
		b.text = NULL;
		return b;	
	}

	int i = 0;
	while(b.text[i] != '\0'){
		if('A' <= b.text[i] && b.text[i] <= 'Z'){
			b.text[i] += 'a'-'A';
		}else if('a' <= b.text[i] && b.text[i] <= 'z'){
		}else{
			int j = 0;
			do{
				b.text[i+j] = b.text[i + j + 1];
				j++;
			}while(b.text[i + j - 1] != '\0');
			i--;
		}
		i++;
	}
	return b;
}

int obstaja(beseda* besede, beseda b, int n){
	int i, j;
	for(i = 0; i < n; i++){
		beseda a = besede[i];
		j = 0;
		while(a.text[j] == b.text[j]){
			if(a.text[j] == '\0'){
				besede[i].frekvenca++;
				return 1;					
			}
			j++;
		}
	}
	return 0;
}

int jePred(char* beseda1, char* beseda2){
	if(beseda1[0] == beseda2[0]  && beseda2[0] == '\0') return 1;
	if(beseda1[0] == beseda2[0]) return jePred(beseda1+1, beseda2+1);
	int i = beseda1[0] - beseda2[0];
	return (i < 0) ? 0 : 1;
}

void uredi(beseda* besede, int n){
	int i, j;	
	for(i = 1; i < n; i++){
		j = i;		
		while(besede[j].frekvenca > besede[j-1].frekvenca
			|| (besede[j].frekvenca == besede[j-1].frekvenca && jePred(besede[j-1].text, besede[j].text))){
			beseda t = besede[j];
			besede[j] = besede[j-1];
			besede[j-1] = t;
			j--;
		}
	}
}

int main(){	
	int n;
	scanf("%d", &n);

	int i = 0;	
	beseda* besede = malloc(sizeof(beseda) * 5001);
	beseda b;
	while(1){
		b = preberiBesedo();
		if(b.text == NULL) break;
		if(b.text[0] == '\0')continue;
		if(!obstaja(besede, b, i)){
			besede[i++] = b; 		
		}	
	}

	uredi(besede, i);

	for(i = 0; i < n; i++){
		if(besede[i].text == NULL || besede[i].text[0] == '\0')break;

		printf("%s %d\n", besede[i].text, besede[i].frekvenca);	
	}

	return 0;
}
