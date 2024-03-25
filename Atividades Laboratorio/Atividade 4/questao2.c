#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarSenha(int numero, int *prioridade) {
    if (*prioridade < 4) {
        printf("Senha %d - Prioridade\n", numero);
        (*prioridade)++;
    } else {
        printf("Senha %d - Normal\n", numero);
        *prioridade = 1; 
    }
}

int main() {
    int i, prioridade = 1;

    srand(time(NULL));

    printf("Gerando senhas de guichê:\n");

    for (i = 1; i <= 10; i++) {
        gerarSenha(i, &prioridade);
    }

    return 0;
}
