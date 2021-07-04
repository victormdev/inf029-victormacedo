#include <stdio.h>

void imprimeQ15(int n);

int main(void)
{ 
  int n = 8;
  imprimeQ15(n);

  return 0;
}

void imprimeQ15(int n){

  if(n % 2 == 0)

  printf("%d\n", n);

  
	if(n>0)

	imprimeQ15(n-1);

}
  