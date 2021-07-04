#include <stdio.h>

void inverter(int x)
{

if (x == 0){
printf("\nEncerrou\n");
}
else{
printf("%d", x % 10);
x = x / 10;
return inverter(x);
}

}


int main()
{

inverter(1234567);

return 0;

} 