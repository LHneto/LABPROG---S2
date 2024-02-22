#include <stdio.h>

int main() {
    int num1, num2;

    printf("Informe o primeiro número: ");
    scanf("%d", &num1);

    printf("Informe o segundo número: ");
    scanf("%d", &num2);

    int diff = num1 - num2;
    
    if (diff)
    {
        printf("O número maior é: %d\n", num1 - (diff & (diff >> (sizeof(int) * 8 - 1))));
    }
    else
    {
        printf("Os números são iguais.\n");
    }

    return 0;
}
