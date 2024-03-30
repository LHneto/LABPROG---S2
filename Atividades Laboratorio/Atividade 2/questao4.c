#include <stdio.h>

int main() {
    int num, isPrime = 1;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    if (num <= 1) {
        isPrime = 0;
    } else {
       
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime) {
        printf("%d é primo.\n", num);
        return 1;
    } else {
        printf("%d não é primo.\n", num);
        return 0;
    }
}