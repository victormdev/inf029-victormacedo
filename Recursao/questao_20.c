#include <stdio.h>
#include <stdlib.h>


int tribonacci(int x)
{
	if(x == 0 || x == 1){
		return 0;
	}
	if(x == 2) {
		return 1;

	}
	return tribonacci(x - 1) + tribonacci(x - 2) + tribonacci(x - 3);
}

int main()
{  
	int resultado;

	resultado = tribonacci(5);

	printf("\n%d", resultado);

  	return 0;

} 