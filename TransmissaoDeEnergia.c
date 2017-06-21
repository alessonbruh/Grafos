#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int e, l, estacao[101], test_num = 1, visitado = 0;

int busca(int g[][e], int origem)
{
    int i;

    estacao[origem] = 1;
    visitado++;
    for (i=0; i<e; i++)
        if (g[origem][i] == 1 && estacao[i] == 0)
            busca(g, i);

    return visitado;
}


int main()
{

    int i, j, x, y;
    int result;

    while(true)
    {
        scanf("%d %d", &e, &l);
        if ((e == 0)&&(l == 0))
            return 0;

        int grafo[e][e];

        memset(grafo, 0, sizeof(grafo[0][0]) *e *e);
        memset(estacao, 0, sizeof(estacao[0]) *e);
        visitado = 0;
        for (i=0; i<l; i++)
        {
            scanf("%d %d", &x, &y);
            grafo[x-1][y-1] = 1;
            grafo[y-1][x-1] = 1;
        }

        result = busca(grafo, 0);

        if (result == e)
            printf("Teste %d\nnormal\n\n", test_num);
        else
            printf("Teste %d\nfalha\n\n", test_num);

        test_num++;
    }

    return 0;
}
