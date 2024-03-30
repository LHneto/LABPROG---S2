#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        printf("Por favor, forneça um valor de n positivo.\n");
        return -1; 
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    }

    int a = 0, b = 1, temp;
    for (int i = 3; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n = 10;
    printf("O %do termo da sequência de Fibonacci é %d\n", n, fibonacci(n));
    return 0;
}