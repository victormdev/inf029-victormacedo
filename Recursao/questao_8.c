#include <stdio.h>
#include <stdlib.h>

int mdc(int x, int y) {

	if( y == 0){

		return x;

	}
    
	mdc(y, x % y);
}


int main()
{   
	int num1 = 8 , num2 = 16;

	int result;

	result = mdc(num1, num2);

	printf("\n%d", result);

  	return 0;

} 
