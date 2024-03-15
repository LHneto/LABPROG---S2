#include <stdio.h>

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    num /= 16; 

    printf("O número %d deslocado à direita por 4 bits é: %d\n", num * 16, num);

    return 0;
}