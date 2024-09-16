#ifndef TRANSACOES_H
#define TRANSACOES_H

#include <stdio.h>

// Definição da estrutura de transação
typedef struct {
    char dataAplicacao[11];
    float valorBruto;
    char Tipo[20];
    char Nome[50];
    char dataVencimento[11];
    char taxaJuros[10]; // String para taxas de juros variáveis
    float valorAplicado;
    float imposto;
} Transacao;

// Declaração das funções comuns
void converterData(const char *data, char *dataISO);
int calcularDiferencaDias(const char *data1, const char *data2);
int calcularQuantidadeMeses(const char *data1, const char *data2);
float calcularImposto(int dias);
void ordenarEAgrupar(Transacao *transacoes, int n);

// Declarações das funções de comparação para ordenação
int compararPorDataAplicacao(const void *a, const void *b);
int compararPorValorBruto(const void *a, const void *b);
int compararPorTipo(const void *a, const void *b);

// Tipo de função para atualizar investimento com rendimentos variáveis
typedef void (*AtualizarInvestimentoFunc)(Transacao *transacao);

#endif // TRANSACOES_H
