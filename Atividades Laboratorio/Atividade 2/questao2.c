#include <stdio.h>

int power(int base, int exponent) {

    if (exponent == 0) {
        return 1;
    }
  
    else if (exponent == 1) {
        return base;
    }
 
    else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int base, exponent;

    printf("Digite o número base: ");
    scanf("%d", &base);
    printf("Digite o expoente (deve ser um número inteiro positivo): ");
    scanf("%d", &exponent);

    if (exponent < 0) {
        printf("O expoente deve ser positivo.\n");
        return 1; 
    }

    int result = power(base, exponent);
    printf("%d elevado a %d é igual a %d\n", base, exponent, result);

    return 0;
}