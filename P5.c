/* P5.c */
/* Lesly Viviane Montúfar Berrios */
/* 11811ETE001 */

#include <stdio.h>
#define N 50

typedef
   unsigned long long int
Bytes8;

typedef
   struct LCG { 
      Bytes8 a, c, m, rand_max, atual; 
   }
LCG;

void semente(LCG * r, Bytes8 seed) {
   // constantes do POSIX [de]rand48, glibc [de]rand48[_r]
   // ULL transforma a constante ’int’ em ’unsigned long long int’
   r->a = 0x5DEECE66DULL;
   r->c = 11ULL;
   r->m = (1ULL << 48);
   r->rand_max = r->m - 1;
   r->atual = seed;
}

Bytes8 lcg_rand(LCG * r) {
   r->atual = (r->a * r->atual + r->c) % r->m;
   return r->atual;
}

double lcg_rand_01(LCG * r) {
   return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros_printa(float *, int, float, float, LCG *);

float somatorio(float *, float *);
float produtorio(float *, float *);

int main(){
   LCG random;
   semente(&random, 123456); 
   
   float vetor[N]; //porque não pode deixar *vetor ?
   char opcao;
   printf("\n\n\t");
   gera_numeros_printa(&vetor[0], N, 0.5, 1.5, &random);
   printf("\n\n\t1 - Somatorio\n\t2 - Produtorio\n\n\t");
   scanf("%c", &opcao);
   switch(opcao){
     case '1':
     printf("\n\t\"%c\" resulta em \"%g\"\n\n", opcao, somatorio(&vetor[0], &vetor[0] + N-1));
     break;
     
     case '2':
     printf("\n\t\"%c\" resulta em \"%g\"\n\n", opcao, produtorio(&vetor[0], &vetor[0] + N-1));
     break;
     
     default:
     	printf("\n\n\tOpcao invalida\n\n");
   }
   return 0;
}

void gera_numeros_printa(float * vetor, int tam, float min, float max, LCG * r) {
   int i;
   for(i = 0; i < tam; i++){
      vetor[i] = (max-min)*lcg_rand_01(r) + min;
      printf("%f  ", vetor[i]);
      if((i+1)%10==0) printf("\n\t");
   }
}

float somatorio(float *inicio_vetor, float *fim_vetor){
   return (inicio_vetor == fim_vetor+1)? 0 : *inicio_vetor + somatorio(inicio_vetor+1, fim_vetor);
}

float produtorio(float *inicio_vetor, float *fim_vetor){
   return (inicio_vetor == fim_vetor+1)? 1 : *inicio_vetor * produtorio(inicio_vetor+1, fim_vetor);
}
