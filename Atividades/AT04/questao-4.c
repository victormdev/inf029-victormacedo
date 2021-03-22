#include <stdio.h>
int* lerNumero();

int main(){
	
    int *vet;
    int i;

    vet = lerNumero();

    for(i = 0; i < 3; i++)
        printf("%d ", vet[i]);

    printf("\n");

	return 0;
}

int* lerNumero() {
	
    static int vet[3];

    printf("Digite o primeiro numero:\n");
    scanf("%d", &vet[0]);

    printf("Digite o segundo numero:\n");
    scanf("%d", &vet[1]);

    printf("Digite o terceiro numero:\n");
    scanf("%d", &vet[2]);

    return vet;
}