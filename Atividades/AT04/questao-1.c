#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float soma(int x, int y)
{
    return x+y;
}
float main()
{
    int x, y;

    printf("Digite o primeiro numero: ");
    scanf("%d", &x);
    printf("Digite o segundo numero:");
    scanf("%d", &y);
		
    printf(" O resultado da soma eh %f", soma(x, y));
    return 0;

}
