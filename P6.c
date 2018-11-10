/* P6.c */
/* Lesly Viviane Montúfar Berrios */
/* 11811ETE001 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265359
#define r 1

typedef struct {
  float x, y;
}Ponto;

int main(){
   int N, i; //stack memory
   Ponto *xy;
   scanf("%i", &N);getchar();
   xy= (Ponto *) malloc(N*sizeof(Ponto)); //heap memory
   printf("%i retorna \" ",N);
   for(i=0; i<N; i++){
     xy->x= r*cos(i*2*pi/(N));
     xy->y= r*sin(i*2*pi/N);
     printf("(%.3f, %.3f) ", xy->x, xy->y);
   }
   printf("\" ");
   free(xy);
   return 0;
}
