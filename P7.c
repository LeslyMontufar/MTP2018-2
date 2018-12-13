/* P7.c */
/* Lesly Viviane Montúfar Berrios */
/* 11811ETE001 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define r 1

typedef struct {
  float x, y;
}Ponto;

void gerarArquivo();
void recuperarPontos();

int main(){
	char option;
	fprintf(stdout, "\n\t1. Gerar arquivos com pontos\n");
	fprintf(stdout, "\t2. Recuperar pontos de arquivo\n\n\t");
	scanf("%c", &option); getchar();

	switch(option){
		case '1':
			gerarArquivo();
			break;

		case '2':
			recuperarPontos();
			break;
	}   

   return 0;
}

void gerarArquivo(){
	FILE *fp;
	Ponto *p;
	int N, i;

	fprintf(stdout, "\n\n\tN: ");
	scanf("%i", &N);getchar();
	p = (Ponto *) malloc(N*sizeof(Ponto));

	for(i=0; i<N; i++){
	   	p[i].x= r*cos(i*2*M_PI/(N-1));
	   	p[i].y= r*sin(i*2*M_PI/(N-1));
	}

	if((fp=fopen("pontos.dat", "wb"))!=NULL){
		fwrite(&N, 1, sizeof(int), fp);
	    fwrite(p, N, sizeof(Ponto), fp);

   		fprintf(stdout, "\n\n\t\"1\" + \"%i\" retorna \"Arquivo gravado\"\n", N);
    }else
		fprintf(stdout, "Erro: nao possivel abrir o arquivo");

   	free(p);	
   	fclose(fp);
}

void recuperarPontos(){
	Ponto *p;
	int N, i, nCol=2;

	FILE *fp;
	if((fp=fopen("pontos.dat", "rb"))!=NULL){
		fread(&N, 1, sizeof(int), fp);
		p = (Ponto *) malloc(N*sizeof(Ponto));
		fread(p, N, sizeof(Ponto), fp);

    }else
		fprintf(stdout, "Error: Impossible to open the file");

	printf("\n\n\t\"2\" retorna \" ");
   	for(i=0; i<N; i++){
    	fprintf(stdout, "(%.3f, %.3f) ", p[i].x, p[i].y);
    	if((i+1)%nCol==0 && i!=N-1)
    		fprintf(stdout, "\n\t");
    }
    printf("\"\n");
	free(p);
	fclose(fp);
}
