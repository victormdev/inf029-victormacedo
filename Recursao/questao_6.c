#include <stdio.h>
#include <stdlib.h>

int potencia(int k, int n){

	if(n == 1){

		return k;
	}

	return k * potencia(k, n - 1);
    
}


int main()
{   
	
	printf("\n%d", potencia(4, 6));

  	return 0;

} 
