#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SENHAS 10

typedef struct {
    int numero;
    bool prioridade;
} Senha;

Senha fila_senhas[MAX_SENHAS];
int tamanho_fila = 0;
int senhas_consumidas = 0;


int gerarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}


void adicionarSenha(bool prioridade) {
    if (tamanho_fila >= MAX_SENHAS) {
        printf("A fila de senhas está cheia.\n");
        return;
    }

    Senha novaSenha;
    novaSenha.numero = tamanho_fila + 1;
    novaSenha.prioridade = prioridade;
    fila_senhas[tamanho_fila++] = novaSenha;

    printf("Senha %d - %s\n", novaSenha.numero, (prioridade ? "Prioridade" : "Normal"));
}


void consumirSenha() {
    if (tamanho_fila == 0) {
        printf("Não há mais senhas disponíveis para consumir.\n");
        return;
    }

    Senha senha = fila_senhas[senhas_consumidas++];
    printf("Chamando senha %d - %s\n", senha.numero, (senha.prioridade ? "Prioridade" : "Normal"));

    
    if (senhas_consumidas == tamanho_fila) {
        senhas_consumidas = 0;
    }
}


void mostrarSenhasRestantes() {
    printf("Senhas restantes:\n");
    for (int i = senhas_consumidas; i < tamanho_fila; i++) {
        Senha senha = fila_senhas[i];
        printf("Senha %d - %s\n", senha.numero, (senha.prioridade ? "Prioridade" : "Normal"));
    }
}

int main() {
    int opcao;

    
    srand(time(NULL));

    do {
        printf("\nSelecione uma opção:\n");
        printf("1. Gerar 10 senhas\n");
        printf("2. Consumir uma senha\n");
        printf("3. Mostrar as senhas restantes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                for (int i = 0; i < MAX_SENHAS; i++) {
                    adicionarSenha(i % 3 == 0); 
                }
                break;
            case 2:
                consumirSenha();
                break;
            case 3:
                mostrarSenhasRestantes();
                break;
            case 0:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}