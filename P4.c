/* P4.c */
/* Lesly Viviane Montúfar Berrios */
/* 11811ETE001 */

/*Funcao de Ackermann*/
#include <stdio.h>

double Ackermann (double , double);
int main(){
   double m, n;
   scanf("%lf%lf", &m, &n);
   printf("\"%g\" + \"%g\" resulta em \"%g\"\n", m, n, Ackermann(m,n));
   return 0;
}

double Ackermann(double m, double n){
   if(m==0) return n+1;
   else if(m>0 && n==0) Ackermann(m-1,1);
   else if(m>0 && n>0) Ackermann(m-1, Ackermann(m, n-1));
}
