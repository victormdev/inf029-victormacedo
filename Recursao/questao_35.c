#include <stdio.h>
#include <stdlib.h>

int binario(int n){

    while(n!=0)

    return (10 * binario( n / 2 ) ) + n % 2;
    // a conta em que se converte o decimal para binário está na divisão sucessiva de n por 2 + a impressão da soma do resto da divisão. 
    // a multiplicação do 10 pelo calculo serve para pegar o numero binario na ordem correta, trazendo o bit mais significativo para a posição inicial                                                                   
} 

int main(){

    int n = 0;

    printf("\n Digite um numero entre 0 e 255 para converter em binario\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 255)){
        printf("\n Numero invalido ou 0\n");
    }
    else
    printf("\n O numero %d em binario eh: %d\n", n, binario(n));

    return 0;

}
