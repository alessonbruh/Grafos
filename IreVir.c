#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph {
    int *ligacoes;
    int visited;
} Graph , *gGraph ;

Graph lista_grafo[2001];
Graph lista_inversa[2001];

void limparLista(int pontos, int estradas) {
    int i;
    for (i=1; i<=pontos; i++) {
        lista_grafo[i].visited = 0;
        lista_inversa[i].visited = 0;
        if (lista_grafo[i].ligacoes != NULL) {
            free(lista_grafo[i].ligacoes);
            free(lista_inversa[i].ligacoes);
        }
        lista_grafo[i].ligacoes = (int*) calloc(estradas+2, sizeof(int));
        lista_inversa[i].ligacoes = (int*) calloc(estradas+2, sizeof(int));
    }
}

void InserirConectivo(int origem, int destino) {
    int i;
    for (i=1; i<=2000; i++) {
        if (lista_grafo[origem].ligacoes[i] == 0){
            lista_grafo[origem].ligacoes[i] = destino;
            return;
        }
    }
}

void listaInversa(int origem, int destino) {
    int i;
    for (i=1; i<=2000; i++) {
        if (lista_inversa[origem].ligacoes[i] == 0){
            lista_inversa[origem].ligacoes[i] = destino;
            return;
        }
    }
}

int dfs_count(int ponto){
    int i, contador = 1, destino;

    lista_grafo[ponto].visited = 1;

    for (i=1; lista_grafo[ponto].ligacoes[i] != 0; i++) {
        destino = lista_grafo[ponto].ligacoes[i];
        if (lista_grafo[destino].visited == 0) {
            contador += dfs_count(destino);
        }
    }

    return contador;
}

int dfs_count_lista_inversa(int ponto){
    int i, contador = 1, destino;

    lista_inversa[ponto].visited = 1;

    for (i=1; lista_inversa[ponto].ligacoes[i] != 0; i++) {
        destino = lista_inversa[ponto].ligacoes[i];
        if (lista_inversa[destino].visited == 0) {
            contador += dfs_count_lista_inversa(destino);
        }
    }

    return contador;
}


int main() {
    int N, M, i, j;
    int V, W, P;

    for (i=1; i<=2000; i++)
        lista_grafo[i].ligacoes = NULL;


    while (true) {
        scanf("%d %d", &N, &M);

        if(N == 0 && M == 0)
            break;
        limparLista(N, M);

        for (j=0; j<M; j++) {

            scanf("%d %d %d", &V, &W, &P);

            InserirConectivo(V, W);
            listaInversa(W, V);
            if (P == 2) {
                InserirConectivo(W, V);
                listaInversa(V, W);
            }
        }

        int count = dfs_count(1);
        int count_lista_inversa = dfs_count_lista_inversa(1);

        if (count == count_lista_inversa && count == N)
            printf("1\n");
        else
            printf("0\n");

    }

    return 0;
}
