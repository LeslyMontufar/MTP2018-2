/* P6.c */
/* Lesly Viviane Montúfar Berrios */
/* 11811ETE001 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define pi 3.14159265359 //tem o M_PI
#define r 1

typedef struct {
  float x, y;
}Ponto;

int main(){
	Ponto *p;
	int N, i, nCol=2;

	fprintf(stdout, "\n\n\tN: ");
	fscanf(stdin, "%i", &N);getchar();

	p = (Ponto *) malloc(N*sizeof(Ponto));

	fprintf(stdout, "\n\n\t\"%i\" retorna \" ",N);
	for(i=0; i<N; i++){
	   	p[i].x= r*cos(i*2*M_PI/(N-1));
	   	p[i].y= r*sin(i*2*M_PI/(N-1));
	   	fprintf(stdout, "(%.3f, %.3f) ", p[i].x, p[i].y);
	   	if((i+1)%nCol==0 && i!=N-1){
	   		fprintf(stdout, "\n\t");
	   	} 		
	}
   fprintf(stdout, "\"\n");	
   return 0;
}
