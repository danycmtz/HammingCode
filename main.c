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
    printf("Hello World, we're Olaf and Dany!\n");
    printf("Add this!\n");
    printf("%d\n",variableentrada);
    printf("%d\n",createhammingcode(0));


    printf("%d\n",sonbitpares(0xA));

    return 0;
}

uint16 createhammingcode(uint16 word){
    uint16 resultado = 0;
    uint16 codigosecuridad=0;
    uint16 grupo1 = 0;
    uint16 grupo2 = 0;
    uint16 grupo3 = 0;
    uint16 grupo4 = 0;
    grupo1 = (word &0x6D5);
    grupo2 = (word &0x5B3);
    grupo3 = (word &0x38F);
    grupo4 = (word &0x07F);
    codigosecuridad = (sonbitpares(grupo1)<<11) + (sonbitpares(grupo2)<<12) +(sonbitpares(grupo3)<<13) + (sonbitpares(grupo4)<<14) ;
    resultado = word + codigosecuridad;
    resultado+= (sonbitpares(resultado)<<15);
    return resultado;
}

uint8 sonbitpares(uint16 word){
    uint8 contador = 0;
    for(int i = 0; i < 16; i++){
        contador += ((word&(1<<i))>>i);
    }
    return contador%2;
}
