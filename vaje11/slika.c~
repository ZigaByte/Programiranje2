#include<stdio.h>
#include<stdlib.h>

char getS(int x, int y, int n, unsigned int **pixels){
	int xx, yy;
	long r =0, g=0, b=0;	
	for(xx =0; xx < n; xx++){			
		for(yy =0; yy< n; yy++){
			int p = pixels[x+xx][y+yy];
			r += (p >> 16)& 255;	
			g += (p >> 8) & 255;
			b += p & 255;
		}
	}	

	long a = (r+b+g)/(3*n*n);
	//printf("%d\n", a);

	if(a < 50)return '@';
	if(a < 70)return '#';
	if(a < 100)return '8';
	if(a < 130)return '&';
	if(a < 160)return 'o';
	if(a < 180)return ':';
	if(a < 200)return '\'';
	if(a < 230)return '.';

	return ' ';
}

int main(){
	char* inputFile = malloc(sizeof(char) * 100);
	char* outputFile = malloc(sizeof(char) * 100);
	int n;
	scanf("%s %s %d", inputFile, outputFile, &n);

	FILE *in = fopen(inputFile, "r");
	FILE *out = fopen(outputFile, "w");
	
	int w, h;
	fscanf(in,"P6\n%d %d\n255\n", &w, &h);
	//printf("%d %d \n", w, h);

	unsigned int **pixels = malloc(sizeof(int*) * w);
	int i;
	for(i = 0; i < w; i++)
		pixels[i] = malloc(sizeof(int) * h);

	int x,y;
	for(y = 0; y < h; y++){
		for(x = 0; x < w; x++){		
			unsigned char cr, cg, cb;
			fscanf(in, "%c%c%c", &cr, &cg, &cb);
							
			unsigned int rgb = cr << 16 | cg << 8 | cb;
			pixels[x][y] = rgb;
		}
	}

	for(y = 0; y < h; y+=n){
		for(x = 0; x < w; x+=n){
			fprintf(out, "%c", getS(x, y, n, pixels));
		}
		fprintf(out, "\n");
	}

	fclose(out);
	fclose(in);

	return 0;
}
