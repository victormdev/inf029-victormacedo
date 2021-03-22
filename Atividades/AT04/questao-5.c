#include <stdio.h>
typedef struct Numero {
    int num1;
    int num2;
    int num3;
    int num4;
} Numero;

Numero lerNumero();

int main(){
	
    Numero numeros = lerNumero();
    printf("Primeiro numero: %d\n", numeros.num1);
    printf("Segundo numero: %d\n", numeros.num2);
    printf("Terceiro numero: %d\n", numeros.num3);
    printf("Quarto numero: %d\n", numeros.num4);

	return 0;
}

Numero lerNumero() {
	
    Numero numeros;

    printf("Digite o primeiro numero:\n");
    scanf("%d", &numeros.num1);

    printf("Digite o segundo numero:\n");
    scanf("%d", &numeros.num2);

    printf("Digite o terceiro numero:\n");
    scanf("%d", &numeros.num3);

    printf("Digite o quarto numero:\n");
    scanf("%d", &numeros.num4);

    return numeros;
}