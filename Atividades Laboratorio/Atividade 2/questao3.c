#include <stdio.h>
#include <stdlib.h>

int power(int base, unsigned int exponent) {
    // Caso base: se o expoente for 0, retorna 1
    if (exponent == 0) {
        return 1;
    }

    return base * power(base, exponent - 1);
}

int main() {
    int base;
    unsigned int exponent;

    printf("Digite o número base: ");
    scanf("%d", &base);
    printf("Digite o expoente (deve ser um número inteiro positivo): ");
    scanf("%u", &exponent);

    int result = power(base, exponent);
    printf("%d elevado a %u é igual a %d\n", base, exponent, result);

    return 0;
}
