#include <stdio.h>

long int hiperFatorial(int n) {
	if(n == 1 || n == 0) {
		return 1;
	}
	long int hiperfat2(int n, int k) {
		if(k == 1) {
			return n;
		}
		return n * hiperfat2(n, k - 1);
	}

	return hiperfat2(n, n) * hiperFatorial(n - 1);
}

int main()
{   

	printf("\n%d", hiperFatorial(5));
    
  	return 0;

}  