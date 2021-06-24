#include <stdio.h>

int fibonaci(y)
{

  if (y == 1 || y == 2)

    return 1;

  else

    return fibonaci(y-1) + fibonaci(y-2);

}


int main(void)
{ 

  int y=5;

  printf("O termo de numero %d, na sequencia de fibonacci eh: %d\n", y, fibonaci(y));

  return 0;

}
 