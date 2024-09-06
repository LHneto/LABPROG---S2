#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
    char dataAplicacao[11];
    float valorBruto;
    char Tipo[20];
    char Nome[50];
    char dataVencimento[11];
    char taxaJuros[10];
    float valorAplicado;
    float imposto;
} Transacao;

const char dataAtual[] = "2024-09-06";

void converterData(const char *data, char *dataISO) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    sprintf(dataISO, "%d-%02d-%02d", ano, mes, dia);
}

int calcularDiferencaDias(const char *data1, const char *data2) {
    struct tm tm1 = {0}, tm2 = {0};
    time_t t1, t2;

    sscanf(data1, "%d-%d-%d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday);
    sscanf(data2, "%d-%d-%d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday);

    tm1.tm_year -= 1900;
    tm1.tm_mon -= 1;
    tm2.tm_year -= 1900;
    tm2.tm_mon -= 1;

    t1 = mktime(&tm1);
    t2 = mktime(&tm2);

    return (int)difftime(t2, t1) / (60 * 60 * 24);
}

float calcularImposto(int dias) {
    if (dias <= 180) return 0.225;
    if (dias <= 360) return 0.20;
    if (dias <= 720) return 0.175;
    return 0.15;
}

void atualizarInvestimento(Transacao *transacao) {
    char dataAplicacaoISO[11];
    char dataAtualISO[11];
    
    converterData(transacao->dataAplicacao, dataAplicacaoISO);
    converterData(dataAtual, dataAtualISO);
    
    int dias = calcularDiferencaDias(dataAplicacaoISO, dataAtualISO);

    float taxaJurosAnual;
    sscanf(transacao->taxaJuros, "%f%% a.a.", &taxaJurosAnual);
    taxaJurosAnual /= 100.0;

    float jurosDiario = pow(1 + taxaJurosAnual, 1.0 / 365.0) - 1;
    transacao->valorBruto = transacao->valorAplicado * pow(1 + jurosDiario, dias);
    transacao->imposto = transacao->valorBruto * calcularImposto(dias);
}

int compararPorDataAplicacao(const void *a, const void *b) {
    return strcmp(((Transacao *)a)->dataAplicacao, ((Transacao *)b)->dataAplicacao);
}

int compararPorValorBruto(const void *a, const void *b) {
    float diff = ((Transacao *)a)->valorBruto - ((Transacao *)b)->valorBruto;
    return (diff > 0) - (diff < 0);
}

int compararPorTipo(const void *a, const void *b) {
    return strcmp(((Transacao *)a)->Tipo, ((Transacao *)b)->Tipo);
}

void ordenarEAgrupar(Transacao *transacoes, int n) {
    qsort(transacoes, n, sizeof(Transacao), compararPorTipo);
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && strcmp(transacoes[j].Tipo, transacoes[i].Tipo) == 0) {
            j++;
        }
        qsort(transacoes + i, j - i, sizeof(Transacao), compararPorValorBruto);
        i = j;
    }
}

int main() {
    int n = 2; 

    Transacao *transacoes = (Transacao *)malloc(n * sizeof(Transacao));

    strcpy(transacoes[0].dataAplicacao, "22/02/2020");
    transacoes[0].valorBruto = 0.00; // Inicialmente zero
    strcpy(transacoes[0].Tipo, "Renda Fixa");
    strcpy(transacoes[0].Nome, "CDB maj");
    strcpy(transacoes[0].dataVencimento, "01/04/2027");
    strcpy(transacoes[0].taxaJuros, "11,5% a.a.");
    transacoes[0].valorAplicado = 915.00;
    transacoes[0].imposto = 0.00; // Inicialmente zero

    strcpy(transacoes[1].dataAplicacao, "23/08/2024");
    transacoes[1].valorBruto = 100.00; // Valor Bruto definido inicialmente
    strcpy(transacoes[1].Tipo, "Despesas");
    strcpy(transacoes[1].Nome, "Aluguel");
    strcpy(transacoes[1].dataVencimento, "23/09/2024");
    strcpy(transacoes[1].taxaJuros, "N/A");
    transacoes[1].valorAplicado = 0.00;
    transacoes[1].imposto = 0.00; // Inicialmente zero

    for (int i = 0; i < n; i++) {
        if (strcmp(transacoes[i].taxaJuros, "N/A") != 0) { // Apenas para investimentos com taxa de juros
            atualizarInvestimento(&transacoes[i]);
        }
    }

    printf("Antes da ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %.2f %s %s %s %s %.2f %.2f\n", 
               transacoes[i].dataAplicacao, 
               transacoes[i].valorBruto, 
               transacoes[i].Tipo, 
               transacoes[i].Nome,
               transacoes[i].dataVencimento,
               transacoes[i].taxaJuros,
               transacoes[i].valorAplicado,
               transacoes[i].imposto);
    }

    ordenarEAgrupar(transacoes, n);

    printf("\nApós a ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %.2f %s %s %s %s %.2f %.2f\n", 
               transacoes[i].dataAplicacao, 
               transacoes[i].valorBruto, 
               transacoes[i].Tipo, 
               transacoes[i].Nome,
               transacoes[i].dataVencimento,
               transacoes[i].taxaJuros,
               transacoes[i].valorAplicado,
               transacoes[i].imposto);
    }

    free(transacoes);

    return 0;
}
