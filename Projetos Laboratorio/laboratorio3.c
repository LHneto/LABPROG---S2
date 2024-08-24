#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char data[11];
    float valor;
    char tipo[20];
    char nome[50];
} Transacao;

int comparar_por_data(const void *a, const void *b) {
    return strcmp(((Transacao *)a)->data, ((Transacao *)b)->data);
}

int comparar_por_valor(const void *a, const void *b) {
    float diff = ((Transacao *)a)->valor - ((Transacao *)b)->valor;
    return (diff > 0) - (diff < 0);
}

int comparar_por_tipo(const void *a, const void *b) {
    return strcmp(((Transacao *)a)->tipo, ((Transacao *)b)->tipo);
}

void ordenar_e_agrupamento(Transacao *transacoes, int n) {
    qsort(transacoes, n, sizeof(Transacao), comparar_por_tipo);

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && strcmp(transacoes[j].tipo, transacoes[i].tipo) == 0) {
            j++;
        }
        qsort(transacoes + i, j - i, sizeof(Transacao), comparar_por_valor);
        i = j;
    }
}

int main() {
    int n = 3;

    Transacao *transacoes = (Transacao *)malloc(n * sizeof(Transacao));

    strcpy(transacoes[0].data, "2024-08-23");
    transacoes[0].valor = 100;
    strcpy(transacoes[0].tipo, "Despesas");
    strcpy(transacoes[0].nome, "Aluguel");

    strcpy(transacoes[1].data, "2024-08-22");
    transacoes[1].valor = 200;
    strcpy(transacoes[1].tipo, "Renda");
    strcpy(transacoes[1].nome, "Salário");

    strcpy(transacoes[2].data, "2024-08-23");
    transacoes[2].valor = 50;
    strcpy(transacoes[2].tipo, "Despesas");
    strcpy(transacoes[2].nome, "Internet");

    printf("Ordenar por Data:\n");
    qsort(transacoes, n, sizeof(Transacao), comparar_por_data);
    for (int i = 0; i < n; i++) {
        printf("%s %.2f %s %s\n", transacoes[i].data, transacoes[i].valor, transacoes[i].tipo, transacoes[i].nome);
    }

    printf("\nOrdenar por Valor:\n");
    qsort(transacoes, n, sizeof(Transacao), comparar_por_valor);
    for (int i = 0; i < n; i++) {
        printf("%s %.2f %s %s\n", transacoes[i].data, transacoes[i].valor, transacoes[i].tipo, transacoes[i].nome);
    }

    printf("\nOrdenar por Tipo:\n");
    qsort(transacoes, n, sizeof(Transacao), comparar_por_tipo);
    for (int i = 0; i < n; i++) {
        printf("%s %.2f %s %s\n", transacoes[i].data, transacoes[i].valor, transacoes[i].tipo, transacoes[i].nome);
    }

    printf("\nOrdenar e Agrupar por Tipo, depois por Valor:\n");
    ordenar_e_agrupamento(transacoes, n);
    for (int i = 0; i < n; i++) {
        printf("%s %.2f %s %s\n", transacoes[i].data, transacoes[i].valor, transacoes[i].tipo, transacoes[i].nome);
    }

    free(transacoes);

    return 0;
}
