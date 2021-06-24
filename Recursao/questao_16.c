#include <stdio.h>

int fatorialDuplo(int num){

	if(num == 1){
		return 1;
	}

	if(num % 2 == 0){
		return 0;
	}
    
	return num * fatorialDuplo(num - 2);
} 

int main()
{   

	printf("\n%d", fatorialDuplo(5));
    
  	return 0;

} 