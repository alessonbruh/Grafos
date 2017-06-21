#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visitado = 0, c, r, visita[5000];
char vetor[5000][31];

int busca(int g[][c], int origem)
{
    int i;

    visita[origem] = 1;
    visitado++;
    for (i=0; i<c; i++)
        if (g[origem][i] == 1 && visita[i] == 0)
            busca(g, i);

    return visitado;
}

int buscaCriatura(char criatura[]){
	int i;
	for(i=0;i<c; i++)
		if(strcmp(criatura, vetor[i]) == 0)
			return i;
	return 0;
}

int main(){

	int i, j, ind, result = 0, maior;

	scanf("%d %d", &c, &r);

	while(r != 0 || c!= 0){
		char criatura[31], predador[31];



		int grafo[c][c];
        for (i = 0; i < c; i++){
            visita[i] = 0;
            for (j = 0; j < c; j++)
                grafo[i][j] = 0;
        }

        for(i=0; i<c; i++)
			scanf("%s", vetor[i]);

        for (i = 0; i<r; i++)
        {
            scanf("%s %s", criatura, predador);
            ind = buscaCriatura(criatura);
            j = buscaCriatura(predador);
            grafo[ind][j] = 1;
            grafo[j][ind] = 1;
        }

        result = 0;
        for(i=0; i<c; i++){
            if(visita[i] == 0)
                maior = busca(grafo, i);
            visitado = 0;
            if(maior>result)
                result = maior;
        }

        printf("%d\n", result);
		scanf("%d %d", &c, &r);
		visitado = result = 0;

	}
	return 0;
}
