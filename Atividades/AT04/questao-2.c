#include <stdio.h>
#include <stdlib.h>

int subtrai(int x, int y, int z)
{
    return x-y-z;
}
int main()
{
    int x, y, z;

    printf("Digite o primeiro numero:");
    scanf("%d", &x);
    printf("Digite o segundo numero:");
    scanf("%d", &y);
    printf("Digite o terceiro numero:");
    scanf("%d", &z);		
    printf("O resultado da subtracao eh %d", subtrai(x, y,z));
    return 0;

}