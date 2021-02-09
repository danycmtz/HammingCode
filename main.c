/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
typedef unsigned short uint16;
typedef unsigned char uint8;
uint16 createhammingcode(uint16 word);

uint16 variableentrada = 0b00110001110;
uint8 sonbitpares(uint16 word);

int main()
{
    printf("Hello World\n");
    printf("%d\n",variableentrada);
    printf("%d\n",createhammingcode(0));


    printf("%d\n",sonbitpares(0xD));

    return 0;
}

uint16 createhammingcode(uint16 word){
    uint16 resultado;
    uint16 codigosecuridad=0;
    uint16 grupo1;
    uint16 grupo2;
    uint16 grupo3;
    uint16 grupo4;
    grupo1 = (word &0x6D5);
    codigosecuridad = (sonbitpares(grupo1)<<11) + (sonbitpares(grupo2)<<12) +(sonbitpares(grupo3)<<13) + (sonbitpares(grupo4)<<14) +(sonbitpares(word)<<1)  ;
    resultado = word + codigosecuridad;
    return resultado;
}

uint8 sonbitpares(uint16 word){
    uint8 contador=0;
    for(int i = 0; i < 16; i++){
        contador += ((word&(1<<i))>>i);
    }
    return contador%2;
}
