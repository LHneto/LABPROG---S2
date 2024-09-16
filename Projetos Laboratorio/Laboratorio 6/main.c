#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transacoes.h"
#include "calculo_investimento.h"
#include "gerenciamento_investimento.h"

void menu() {
    printf("1. Adicionar Investimento\n");
    printf("2. Excluir Investimento\n");
    printf("3. Editar Investimento\n");
    printf("4. Mostrar Investimentos\n");
    printf("5. Atualizar Investimentos\n");
    printf("6. Ordenar e Agrupar Investimentos\n");
    printf("7. Sair\n");
}

void salvarDados(const Transacao *transacoes, int n) {
    FILE *file = fopen("investimentos.dat", "wb");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para salvar dados.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, file); // Salvar o número de investimentos
    fwrite(transacoes, sizeof(Transacao), n, file); // Salvar os investimentos
    fclose(file);
    printf("Dados salvos com sucesso.\n");
}

void carregarDados(Transacao **transacoes, int *n) {
    FILE *file = fopen("investimentos.dat", "rb");
    if (file == NULL) {
        fprintf(stderr, "Nenhum dado encontrado. Novo arquivo será criado.\n");
        return;
    }
    fread(n, sizeof(int), 1, file); // Carregar o número de investimentos
    *transacoes = (Transacao *)malloc(*n * sizeof(Transacao));
    if (*transacoes == NULL) {
        fprintf(stderr, "Erro ao alocar memória para carregar dados.\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fread(*transacoes, sizeof(Transacao), *n, file); // Carregar os investimentos
    fclose(file);
    printf("Dados carregados com sucesso.\n");
}

void editarInvestimento(Transacao *transacao) {
    printf("Digite a nova data de aplicação (dd/mm/aaaa): ");
    fgets(transacao->dataAplicacao, sizeof(transacao->dataAplicacao), stdin);
    transacao->dataAplicacao[strcspn(transacao->dataAplicacao, "\n")] = '\0';

    printf("Digite o novo tipo: ");
    fgets(transacao->Tipo, sizeof(transacao->Tipo), stdin);
    transacao->Tipo[strcspn(transacao->Tipo, "\n")] = '\0';

    printf("Digite o novo nome: ");
    fgets(transacao->Nome, sizeof(transacao->Nome), stdin);
    transacao->Nome[strcspn(transacao->Nome, "\n")] = '\0';

    printf("Digite a nova data de vencimento (dd/mm/aaaa): ");
    fgets(transacao->dataVencimento, sizeof(transacao->dataVencimento), stdin);
    transacao->dataVencimento[strcspn(transacao->dataVencimento, "\n")] = '\0';

    printf("Digite a nova taxa de juros (xx,x%% a.a.): ");
    fgets(transacao->taxaJuros, sizeof(transacao->taxaJuros), stdin);
    transacao->taxaJuros[strcspn(transacao->taxaJuros, "\n")] = '\0';

    printf("Digite o novo valor aplicado: ");
    scanf("%f", &transacao->valorAplicado);
    getchar(); // Consumir o caractere de nova linha
}

void mostrarInvestimentos(const Transacao *transacoes, int n) {
    printf("Investimentos:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s %.2f %s %s %s %s %.2f %.2f\n",
               i + 1,
               transacoes[i].dataAplicacao,
               transacoes[i].valorBruto,
               transacoes[i].Tipo,
               transacoes[i].Nome,
               transacoes[i].dataVencimento,
               transacoes[i].taxaJuros,
               transacoes[i].valorAplicado,
               transacoes[i].imposto);
    }
}

int main() {
    Transacao *transacoes = NULL;
    int n = 0;

    // Carregar dados ao iniciar o programa
    carregarDados(&transacoes, &n);

    int opcao;
    do {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Para consumir o caractere de nova linha após o número

        if (opcao == 1) { // Adicionar Investimento
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
            getchar(); // Consumir o caractere de nova linha

            nova.imposto = 0.00; // Inicialmente zero
            adicionarInvestimento(&transacoes, &n, nova);

        } else if (opcao == 2) { // Excluir Investimento
            int index;
            printf("Digite o índice do investimento a ser excluído: ");
            scanf("%d", &index);
            getchar(); // Consumir o caractere de nova linha
            excluirInvestimento(&transacoes, &n, index - 1); // Ajustar índice para base 0

        } else if (opcao == 3) { // Editar Investimento
            int index;
            printf("Digite o índice do investimento a ser editado: ");
            scanf("%d", &index);
            getchar(); // Consumir o caractere de nova linha

            if (index < 1 || index > n) {
                printf("Índice inválido!\n");
                continue;
            }

            editarInvestimento(&transacoes[index - 1]); // Ajustar índice para base 0

        } else if (opcao == 4) { // Mostrar Investimentos
            mostrarInvestimentos(transacoes, n);

        } else if (opcao == 5) { // Atualizar Investimentos
            for (int i = 0; i < n; i++) {
                atualizarInvestimento(&transacoes[i]);
            }

        } else if (opcao == 6) { // Ordenar e Agrupar Investimentos
            ordenarEAgrupar(transacoes, n);

        } else if (opcao != 7) { // Sair
            printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    // Salvar dados ao sair do programa
    salvarDados(transacoes, n);

    free(transacoes);
    return 0;
}
