#include <stdio.h>

int main() {
    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    int diff = num1 - num2;

    int Maior = ((diff >> 31) & 1) | ((!!diff) & !(diff & (1 << 31)));

    if (Maior) {
        printf("O maior número é: %d\n", num1);
    } else if (diff) {
        printf("O maior número é: %d\n", num2);
    } else {
        printf("Os números são iguais.\n");
    }

    return 0;
}
