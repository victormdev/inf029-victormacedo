#include <stdio.h>

void imprimeq12(int n);

int main(void)
{ 
  int n = 8;
  imprimeq12(n);

  return 0;
}

void imprimeq12(int n){

	if(n>0)

	imprimeq12(n-1);

	printf("%d\n", n);
}
  