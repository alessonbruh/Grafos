#include <stdio.h>
#include <queue>
using namespace std;
#define CITY_LIMIT 50
#define R_LIMIT 100000000

int grafo[CITY_LIMIT][CITY_LIMIT];
int r[CITY_LIMIT];

void dijkstra(int n, int origem)
{
    for (int i = 0; i < n; i++)
    {
        r[i] = R_LIMIT;
    }

    r[origem] = 0;
    priority_queue<pair<int, int> > heap;
    heap.push(make_pair(0, origem));

    while (!heap.empty())
    {
        int u = heap.top().second;
        heap.pop();

        for (int i = 0; i < n; i++)
        {
            if (grafo[u][i] == 1 && r[u] + 1 <= r[i])
            {
                r[i] = r[u] + 1;
                heap.push(make_pair(r[i], i));
            }
        }
    }
}

int main()
{
    int c, e, l, p, o, d;
    int test_num = 0;

    while (1)
    {
        scanf("%d %d %d %d", &c, &e, &l, &p);
        if (c == 0 && e == 0 && l == 0 && p == 0)
            break;

        for (int i = 0; i < c; i++)
            for (int j = 0; j < c; j++)
                grafo[i][j] = 0;

        for (int i = 0; i < e; i++)
        {
            scanf("%d %d", &o, &d);
            grafo[o-1][d-1] = 1;
            grafo[d-1][o-1] = 1;
        }

        dijkstra(c, l-1);

        printf("Teste %d\n", ++test_num);
        bool espaco = true;
        for (int i = 0; i < c; i++)
        {
            if (i != l-1 && r[i] <= p)
            {
                if (espaco)
                    printf("%d", i+1);
                else
                    printf(" %d", i+1);
                espaco = false;
            }
        }
        printf("\n\n");
    }
    return 0;
}
