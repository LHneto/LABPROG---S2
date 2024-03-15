#include <stdio.h>

int main() {
    int num_signed;

    printf("Digite um número inteiro: ");
    scanf("%d", &num_signed);

    unsigned int num_unsigned = *(unsigned int*)&num_signed;

    printf("O número inteiro %d armazenado como unsigned int é: %u\n", num_signed, num_unsigned);

    return 0;
}