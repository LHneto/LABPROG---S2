#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciamento_investimento.h"

void adicionarInvestimento(Transacao **transacoes, int *n, Transacao novaTransacao) {
    *transacoes = (Transacao *)realloc(*transacoes, (*n + 1) * sizeof(Transacao));
    if (*transacoes == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    (*transacoes)[*n] = novaTransacao;
    (*n)++;
}

void excluirInvestimento(Transacao **transacoes, int *n, int index) {
    if (index < 0 || index >= *n) {
        fprintf(stderr, "Índice inválido para exclusão\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        (*transacoes)[i] = (*transacoes)[i + 1];
    }
    *transacoes = (Transacao *)realloc(*transacoes, (*n - 1) * sizeof(Transacao));
    if (*transacoes == NULL && *n > 1) {
        fprintf(stderr, "Erro ao realocar memória\n");
        exit(EXIT_FAILURE);
    }
    (*n)--;
}

void atualizarInvestimentoNoGerenciamento(Transacao *transacoes, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(transacoes[i].taxaJuros, "N/A") != 0) {
            atualizarInvestimento(&transacoes[i]);
        }
    }
}
