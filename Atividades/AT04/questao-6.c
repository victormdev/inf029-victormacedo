#include <stdio.h>
char* lerLetras();

int main(){
	
    char *vet;
    int i;

    vet = lerLetras();

    for(i = 0; i < 3; i++)
        printf("%c ", vet[i]);

    printf("\n");

	return 0;
}

char* lerLetras() {
	
    static char vet[3];

    printf("Digite tres letras:\n");
    scanf("%c %c %c", &vet[0], &vet[1], &vet[2]);

    return vet;
}