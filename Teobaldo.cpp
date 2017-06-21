#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
using namespace std;


int grafo[101][101];
int VetorOrigem[101], VetorAux[101];

int main()
{
    int j,k, contador = 0, C, L, S, E, D;;
    while(1)
    {
        cin>>C>>L;
        //scanf("%d %d",&C,&L);

        if((C==0) && (L==0))
            return 0;

        for(int i=1; i<=C; i++)
        {
            for(int j=i; j<=C; j++)
            {
                grafo[i][j] = 0;
                grafo[j][i] = 0;
            }
        }

        for(int l=1; l<=L; l++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            //cin>>a>>b;
            grafo[a][b] = 1;
            grafo[b][a] = 1;
        }

        cin>>S>>E>>D;
        //scanf("%d %d %d",&S,&E,&D);


        for(int i=1; i<=C; i++)
        VetorOrigem[i] = 0;

    VetorOrigem[S] = 1;

    for(int i=1; i<=D; i++)
    {

        for(int j=1; j<=C; j++)
        {
            contador = 0;
            for(int k=1; k<=C; k++)
                if(grafo[k][j]==1  && VetorOrigem[k] == 1)
                {
                    contador = 1;
                    break;
                }

            VetorAux[j] = contador;
        }
        for(int c=1; c<=C; c++)
            VetorOrigem[c] = VetorAux[c];
    }
    if( VetorOrigem[E]>0 )
            printf("Yes, Teobaldo can travel.\n");
        else
            printf("No, Teobaldo can not travel.\n");
    }
}
