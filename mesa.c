#include<stdio.h>

#define MAX 100

int main() {

    int pessoas, relacoes, instancia = 1;
    while (scanf("%d %d", &pessoas, &relacoes) != EOF) {
        int mtRelacoes[MAX][MAX];
        int relPes1, relPes2, i, j, k;
        int posIncluir[pessoas];
        for (i = 0; i < pessoas; i++) {
            posIncluir[i] = 0;
        }
        for (i = 0; i < relacoes; i++) { // ler as relações de amizade e armazenar na matriz
            scanf("%d %d", &relPes1, &relPes2);
            mtRelacoes[relPes1 - 1][posIncluir[relPes1 - 1]] = relPes2;
            posIncluir[relPes1 - 1]++;
            mtRelacoes[relPes2 - 1][posIncluir[relPes2 - 1]] = relPes1;
            posIncluir[relPes2 - 1]++;
        }
        for (i = 0; i < pessoas; i++) { // marcar final do array
            mtRelacoes[i][posIncluir[i]] = '0';
        }

        int possivel;

        //Lógica para resultado final começa aqui
        for (i = 0; i < pessoas; i++) {
            int pes1, pes2;
            for (j = 0; j < pessoas; j++) {
                if (mtRelacoes[i][j] == 0 || (j + 1 < pessoas && mtRelacoes[i][j] != 0 && mtRelacoes[i][j + 1] == 0)) {
                    break;
                }
                pes1 = mtRelacoes[i][j];
                pes2 = mtRelacoes[i][j + 1];
                //verifica se o pes1 é amigo de pes2, caso for é impossível realizar a tarefa
                if (pes2 != 0) {
                    for (k = 0; k < pessoas; k++) {
                        if (mtRelacoes[pes1 - 1][k] == pes2) {
                            possivel = 0;
                            goto externo;
                        }
                    }
                }
            }
            possivel = 1;
        }

externo:
        printf("Instancia %d\n", instancia++);
        if (possivel) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
        printf("\n");

    }

    return 0;
}