#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int vetor[], int esq, int dir) {
    if (esq < dir) {
        int pivo = vetor[dir];
        int i = esq - 1;

        for (int j = esq; j < dir; j++) {
            if (vetor[j] < pivo) {
                i++;
                trocar(&vetor[i], &vetor[j]);
            }
        }

        trocar(&vetor[i + 1], &vetor[dir]);

        int p = i + 1;

        quickSort(vetor, esq, p - 1);
        quickSort(vetor, p + 1, dir);
    }
}

void merge(int vetor[], int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = vetor[esq + i];
    for (int j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];

    int i = 0;
    int j = 0;
    int k = esq;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        mergeSort(vetor, esq, meio);
        mergeSort(vetor, meio + 1, dir);

        merge(vetor, esq, meio, dir);
    }
}

void heapify(int vetor[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && vetor[esq] > vetor[maior])
        maior = esq;

    if (dir < n && vetor[dir] > vetor[maior])
        maior = dir;

    if (maior != i) {
        trocar(&vetor[i], &vetor[maior]);
        heapify(vetor, n, maior);
    }
}

void heapSort(int vetor[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i);

    for (int i = n - 1; i >= 0; i--) {
        trocar(&vetor[0], &vetor[i]);
        heapify(vetor, i, 0);
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor ordenado: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    quickSort(vetor, 0, tamanho - 1);
    imprimirVetor(vetor, tamanho);

    int vetor2[] = {64, 25, 12, 22, 11};
    mergeSort(vetor2, 0, tamanho - 1);
    imprimirVetor(vetor2, tamanho);

    int vetor3[] = {64, 25, 12, 22, 11};
    heapSort(vetor3, tamanho);
    imprimirVetor(vetor3, tamanho);

    return 0;
}