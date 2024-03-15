#include <stdio.h>

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    int resultado = num & 1;

    printf("O número %d é %s.\n", num, resultado ? "ímpar (1)" : "par (0)");

    return 0;
}