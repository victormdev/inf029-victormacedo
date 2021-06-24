#include <stdio.h>
#include <stdlib.h>

int somarVetor(int vet[], int x){

	if(x == 1){

		return vet[0];

	}

	return vet[x - 1] + somarVetor(vet, x - 1);
}

int main()
{   
	int vet[4] ={10,20,15,10};

	printf("\n%d", somarVetor(vet, 4));

  	return 0;

} 