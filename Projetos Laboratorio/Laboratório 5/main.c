#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transacoes.h"
#include "calculo_investimento.h"
#include "gerenciamento_investimento.h"

void menu() {
    printf("1. Adicionar Investimento\n");
    printf("2. Excluir Investimento\n");
    printf("3. Atualizar Investimentos\n");
    printf("4. Ordenar e Agrupar Investimentos\n");
    printf("5. Mostrar Investimentos\n");
    printf("6. Sair\n");
}

int main() {
    Transacao *transacoes = NULL;
    int n = 0;

    int opcao;
    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Para consumir o caractere de nova linha após o número

        if (opcao == 1) {
            Transacao nova;
            printf("Digite a data de aplicação (dd/mm/aaaa): ");
            fgets(nova.dataAplicacao, sizeof(nova.dataAplicacao), stdin);
            nova.dataAplicacao[strcspn(nova.dataAplicacao, "\n")] = '\0';

            printf("Digite o tipo: ");
            fgets(nova.Tipo, sizeof(nova.Tipo), stdin);
            nova.Tipo[strcspn(nova.Tipo, "\n")] = '\0';

            printf("Digite o nome: ");
            fgets(nova.Nome, sizeof(nova.Nome), stdin);
            nova.Nome[strcspn(nova.Nome, "\n")] = '\0';

            printf("Digite a data de vencimento (dd/mm/aaaa): ");
            fgets(nova.dataVencimento, sizeof(nova.dataVencimento), stdin);
            nova.dataVencimento[strcspn(nova.dataVencimento, "\n")] = '\0';

            printf("Digite a taxa de juros (xx,x%% a.a.): ");
            fgets(nova.taxaJuros, sizeof(nova.taxaJuros), stdin);
            nova.taxaJuros[strcspn(nova.taxaJuros, "\n")] = '\0';

            printf("Digite o valor aplicado: ");
            scanf("%f", &nova.valorAplicado);

            nova.imposto = 0.00; // Inicialmente zero
            adicionarInvestimento(&transacoes, &n, nova);

        } else if (opcao == 2) {
            int index;
            printf("Digite o índice do investimento a ser excluído: ");
            scanf("%d", &index);
            excluirInvestimento(&transacoes, &n, index);

        } else if (opcao == 3) {
            for (int i = 0; i < n; i++) {
                atualizarInvestimento(&transacoes[i]);
            }

        } else if (opcao == 4) {
            ordenarEAgrupar(transacoes, n);

        } else if (opcao == 5) {
            printf("Investimentos:\n");
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

        } else if (opcao != 6) {
            printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    free(transacoes);
    return 0;
}
