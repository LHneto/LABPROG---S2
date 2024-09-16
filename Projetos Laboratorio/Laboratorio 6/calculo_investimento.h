#ifndef CALCULO_INVESTIMENTO_H
#define CALCULO_INVESTIMENTO_H

#include "transacoes.h"

// Declaração das funções para cálculo de investimento
void atualizarInvestimento(Transacao *transacao);
void atualizarInvestimentoIPCA(Transacao *transacao);

// Declaração de funções auxiliares
void calcularJurosMensal(Transacao *transacao, const float *taxasJurosMensais, int numMeses);

#endif // CALCULO_INVESTIMENTO_H
