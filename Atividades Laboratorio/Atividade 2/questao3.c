#include <stdio.h>
#include <math.h>

void power(int base, int exponent) {
    double result = pow(base, exponent);
    printf("%d elevado a %d é igual a %.0lf\n", base, exponent, result);
}

int main() {
    int base, exponent;

    printf("Digite o número base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &exponent);

    power(base, exponent);

    return 0;
}