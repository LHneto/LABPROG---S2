#include <stdio.h>

int main() {
    int opcao;
    float num1, num2, resultado;

    while (1) {
        printf("\nSelecione uma opção:\n");
        printf("1. Calculadora de soma\n");
        printf("2. Calculadora de subtração\n");
        printf("3. Calculadora de multiplicação\n");
        printf("4. Calculadora de divisão\n");
        printf("5. Calculadora de resto\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo do programa. Até mais!\n");
            break;
        }

        switch(opcao) {
            case 1:
                printf("Digite dois números para somar: ");
                scanf("%f %f", &num1, &num2);
                resultado = num1 + num2;
                printf("O resultado da soma é: %.2f\n", resultado);
                break;
            case 2:
                printf("Digite dois números para subtrair: ");
                scanf("%f %f", &num1, &num2);
                resultado = num1 - num2;
                printf("O resultado da subtração é: %.2f\n", resultado);
                break;
            case 3:
                printf("Digite dois números para multiplicar: ");
                scanf("%f %f", &num1, &num2);
                resultado = num1 * num2;
                printf("O resultado da multiplicação é: %.2f\n", resultado);
                break;
            case 4:
                printf("Digite dois números para dividir: ");
                scanf("%f %f", &num1, &num2);
                if (num2 != 0) {
                    resultado = num1 / num2;
                    printf("O resultado da divisão é: %.2f\n", resultado);
                } else {
                    printf("Não é possível dividir por zero!\n");
                }
                break;
            case 5:
                printf("Digite dois números para encontrar o resto da divisão: ");
                scanf("%f %f", &num1, &num2);
                if (num2 != 0) {
                    resultado = (int)num1 % (int)num2;
                    printf("O resto da divisão é: %.2f\n", resultado);
                } else {
                    printf("Não é possível encontrar o resto, pois o segundo número é zero!\n");
                }
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}