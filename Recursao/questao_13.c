#include <stdio.h>

void imprimeQ13(int n);

int main(void)
{ 
  int n = 8;
  imprimeQ13(n);

  return 0;
}

void imprimeQ13(int n){

	printf("%d\n", n);

    if(n>0)

	imprimeQ13(n-1);

}
 