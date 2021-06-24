#include <stdio.h>

void imprimeq14(int n);

int main(void)
{ 
  int n = 8;
  imprimeq14(n);

  return 0;
}

void imprimeq14(int n){

if (n>0)

  if(n % 2 == 0)
    
	imprimeq14(n-1);

printf("%d\n", n);

}
   