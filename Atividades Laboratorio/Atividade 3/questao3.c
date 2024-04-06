#include <stdio.h>

int buscaBinaria(int vetor[], int inicio, int fim, int alvo) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == alvo)
            return meio;

        if (vetor[meio] < alvo)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {11, 12, 22, 25, 64};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int alvo = 25;
    int resultado = buscaBinaria(vetor, 0, tamanho - 1, alvo);

    if (resultado != -1)
        printf("%d encontrado no índice %d\n", alvo, resultado);
    else
        printf("%d não encontrado no vetor\n", alvo);

    imprimirVetor(vetor, tamanho);

    return 0;
}