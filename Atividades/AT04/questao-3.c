#include <stdio.h>
#include <stdlib.h>

int fatorial(int num) {
    if (num >= 0) {
        int i = 1;
        while (num > 0) {
            i = i*num;
            num--;
        }
        return i;
    } else {
        return -1;
    }
}


int main(){
	int num;
    printf("Digite um numero para calcular o seu fatorial: \n");
    scanf("%d", &num);
	
	if(fatorial(num)==-1){
		printf("Digite outro numero!");
	}
	else{
		printf("resultado: %d", fatorial(num));
	}
return 0;
}