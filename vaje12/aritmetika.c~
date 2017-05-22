#include<stdio.h>
#include<stdlib.h>

int toInt(char* string){
	int n = 0, i = 0;
	while(string[i] != '\0'){
		n = n * 10;
		char c = string[i];
		if(c >= '0' || c <= '9'){
			n = n + (c - '0');
		}
		i++;
	}
	return n;
}

int getValue(char* string){
	// Look for the last thing
	//printf("%s\n", string);

	int n = 0, lastAdd = -1, lastMul = -1;
	while(string[n] != '\0'){
		if(string[n] == '+' || string[n] == '-')
			lastAdd = n;	
		if(string[n] == '*' || string[n] == '/')
			lastMul = n;	
	
		n++;
	}
	if(lastAdd == -1 && lastMul == -1)
		return toInt(string);
	else{
		int t = lastAdd;
		if(t == -1) t = lastMul;

		char temporary = string[t];
		string[t] = '\0'; 
		int left = getValue(string);
		string[t] = temporary;
		int right = getValue(string + t + 1);
	
		if(string[t] == '+')return left + right;
		if(string[t] == '-')return left - right;
		if(string[t] == '*')return left * right;
		if(string[t] == '/')return left / right;
		
	}
}

int main(){
	char* izraz = malloc(sizeof(char) * 1001);
	scanf("%s", izraz);
	printf("%d\n", getValue(izraz));
	
}
