/* P2.c */
/* Lesly Viviane Montúfar Berrios */
/* 11811ETE001 */
#include<stdio.h>
#define maxBits 20

int length(char str[]){
  int i;
  for(i=0; str[i]; i++);
  return i;
}

void removeZeros(char bits[]){
  int i=0, flag=0, index=0;
  for(;i<=maxBits; i++){
    if(bits[i]!='0') flag=1;
    if(flag==1){
      bits[index]=bits[i];
      index++;
    }
  }
  bits[index]=0;
}

int toDecimal(int base, char bin[]){
   int i, dec=0, potencia=1, b;
   for(i=length(bin)-1; i>=0; i--){
      if(bin[i]<='9') b=bin[i]-'0';
      else b=bin[i]-'A'+10;
     
     dec+=b*potencia;
     potencia*=base;
   }
   return dec;
}

void fromDecimal(int base, int dec, char bits[]){
  int i, flag=0;
  for(i=maxBits; i>=0; i--){
    bits[i]=dec%base+'0';
    dec/=base;
    if(bits[i]>'9') bits[i]='A'-1+(bits[i]-'9');
  }
  removeZeros(bits);
}

int main(){
   int opcao, dec;
   char bits[256];
   printf("1. Binario para Decimal\n");
   printf("2. Binario para Hexadecimal\n");
   printf("3. Hexadecimal para Decimal\n");
   printf("4. Hexadecimal para Binario\n");
   printf("5. Decimal para Binario\n");
   printf("6. Decimal para Hexadecimal\n");
   printf("7. Octal para Decimal\n");
   printf("8. Decimal para Octal\n\n");
   scanf("%i", &opcao);getchar();
   if(opcao==1 || opcao==2 || opcao==3 || opcao==4 || opcao==7)
     scanf("%s", bits);
     
   switch(opcao){
     case 1:
     printf("\"%i\" + \"%s\" retorna \"%i\"\n", opcao, bits, toDecimal(2, bits));
     break;
     
     case 2:
     printf("\"%i\" + \"%s\" retorna ", opcao, bits);
     fromDecimal(16,toDecimal(2,bits), bits);
     printf("\"%s\"\n", bits);
     break;
     
     case 3:
     printf("\"%i\" + \"%s\" retorna \"%i\"\n", opcao, bits, toDecimal(16, bits));
     break;
     
     case 4:
     printf("\"%i\" + \"%s\" retorna ", opcao, bits);
     fromDecimal(2,toDecimal(16,bits), bits);
     printf("\"%s\"\n", bits);
     break;
     
     case 5:
     scanf("%i", &dec);
     fromDecimal(2, dec, bits);
     printf("\"%i\" + \"%i\" retorna \"%s\"\n", opcao, dec, bits);
     break;
     
     case 6:
     scanf("%i", &dec);
     fromDecimal(16, dec, bits);
     printf("\"%i\" + \"%i\" retorna \"%s\"\n", opcao, dec, bits);
     break;
     
     case 7:
     printf("\"%i\" + %s retorna \"%i\"\n", opcao, bits, toDecimal(8, bits));
     break;
     
     case 8:
     scanf("%i", &dec);
     fromDecimal(8, dec, bits);
     printf("\"%i\" + \"%i\" retorna \"%s\"\n", opcao, dec, bits);
     break;

   }
   return 0;
}
