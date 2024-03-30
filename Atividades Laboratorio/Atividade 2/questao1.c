#include <stdio.h>

int memo[100];

int fibonacci(int n) {
    if (n <= 0) {
        printf("Digite um valor de n positivo.\n");
        return -1; 
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (memo[n] != 0) {
        return memo[n]; 
    } else {
        memo[n] = fibonacci(n - 1) + fibonacci(n - 2); 
        return memo[n];
    }
}

int main() {
    int n;

    for (int i = 0; i < 100; i++) {
        memo[i] = 0;
    }

    printf("Digite um valor inteiro positivo para n: ");
    scanf("%d", &n);

    int result = fibonacci(n);
    if (result != -1) {
        printf("O %d-ésimo termo da sequência de Fibonacci é %d\n", n, result);
    }

    return 0;
}
