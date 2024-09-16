#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "calculo_investimento.h"

// Função auxiliar para converter data no formato ISO
void converterData(const char *data, char *dataISO) {
    int dia, mes, ano;
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        fprintf(stderr, "Erro ao converter a data: %s\n", data);
        exit(EXIT_FAILURE);
    }
    sprintf(dataISO, "%d-%02d-%02d", ano, mes, dia);
}

// Função para calcular a diferença em dias entre duas datas
int calcularDiferencaDias(const char *data1, const char *data2) {
    struct tm tm1 = {0}, tm2 = {0};
    time_t t1, t2;

    if (sscanf(data1, "%d-%d-%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday) != 3 ||
        sscanf(data2, "%d-%d-%d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday) != 3) {
        fprintf(stderr, "Erro ao calcular a diferença de dias\n");
        exit(EXIT_FAILURE);
    }

    tm1.tm_year -= 1900;
    tm1.tm_mon -= 1;
    tm2.tm_year -= 1900;
    tm2.tm_mon -= 1;

    t1 = mktime(&tm1);
    t2 = mktime(&tm2);

    if (t1 == (time_t)-1 || t2 == (time_t)-1) {
        fprintf(stderr, "Erro ao converter o tempo\n");
        exit(EXIT_FAILURE);
    }

    return (int)difftime(t2, t1) / (60 * 60 * 24);
}

// Função para calcular a quantidade de meses entre duas datas
int calcularQuantidadeMeses(const char *data1, const char *data2) {
    struct tm tm1 = {0}, tm2 = {0};
    int meses;

    if (sscanf(data1, "%d-%d-%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday) != 3 ||
        sscanf(data2, "%d-%d-%d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday) != 3) {
        fprintf(stderr, "Erro ao calcular a quantidade de meses\n");
        exit(EXIT_FAILURE);
    }

    tm1.tm_year -= 1900;
    tm1.tm_mon -= 1;
    tm2.tm_year -= 1900;
    tm2.tm_mon -= 1;

    meses = (tm2.tm_year - tm1.tm_year) * 12 + (tm2.tm_mon - tm1.tm_mon);
    if (tm2.tm_mday < tm1.tm_mday) {
        meses--;
    }

    return meses;
}

// Função para calcular o imposto sobre o valor bruto
float calcularImposto(int dias) {
    if (dias <= 180) return 0.225;
    if (dias <= 360) return 0.20;
    if (dias <= 720) return 0.175;
    return 0.15;
}

// Função para calcular o rendimento com taxas variáveis mensais
void calcularJurosMensal(Transacao *transacao, const float *taxasJurosMensais, int numMeses) {
    float valor = transacao->valorAplicado;
    for (int i = 0; i < numMeses; i++) {
        valor *= (1 + taxasJurosMensais[i]);
    }
    transacao->valorBruto = valor;
}

// Função para atualizar o investimento com rendimentos variáveis
void atualizarInvestimentoIPCA(Transacao *transacao) {
    // Exemplo de taxas de juros mensais (em decimal, e.g., 0.01 para 1%)
    float taxasJurosMensais[] = {0.01, 0.02, 0.015}; // Exemplo de taxas
    int numMesesTaxas = sizeof(taxasJurosMensais) / sizeof(taxasJurosMensais[0]);

    char dataAtualISO[11];
    converterData("2024-09-06", dataAtualISO);

    int meses = calcularQuantidadeMeses(transacao->dataAplicacao, dataAtualISO);
    calcularJurosMensal(transacao, taxasJurosMensais, numMesesTaxas);

    transacao->imposto = transacao->valorBruto * calcularImposto(meses * 30); // Exemplo simples, converter meses para dias
}

// Função para atualizar investimento com taxa fixa
void atualizarInvestimento(Transacao *transacao) {
    AtualizarInvestimentoFunc atualizarFunc;

    if (strcmp(transacao->Tipo, "IPCA") == 0) {
        atualizarFunc = atualizarInvestimentoIPCA;
    } else {
        // Implementar outros tipos de atualização
        fprintf(stderr, "Tipo de investimento não suportado\n");
        return;
    }

    atualizarFunc(transacao);
}
