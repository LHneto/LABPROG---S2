#ifndef GERENCIAMENTO_INVESTIMENTO_H
#define GERENCIAMENTO_INVESTIMENTO_H

#include "transacoes.h"

// Declaração das funções para gerenciamento de investimentos
void adicionarInvestimento(Transacao **transacoes, int *n, Transacao novaTransacao);
void excluirInvestimento(Transacao **transacoes, int *n, int index);
void atualizarInvestimentoNoGerenciamento(Transacao *transacoes, int n);

#endif // GERENCIAMENTO_INVESTIMENTO_H
