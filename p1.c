/* P1.c */
/* Lesly Viviane Montúfar Berrios */
/* 11811ETE001 */
#include<stdio.h>

int main(){
	int est=0,i;
	char bits[256];
	scanf("%s", bits);
	for(i=0;bits[i];i++){
		if(est==0 && bits[i]=='1') est=1;
		else if(est==1){
			est = (bits[i]=='0')? 2:0;
		}
		else if(est==2 && bits[i]=='0') est=1;
	}
	printf("\"%s\" %s", bits, est==0? "e multiplo de 3\n":"nao e\n");
	return 0;
}