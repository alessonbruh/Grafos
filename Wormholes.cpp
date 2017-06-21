#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define A 100000

int grafo[2001][2002];
int distancia[2001], n, m;

void dijkstra()
{
	int j;
    for (int i = 0; i < n; i++)
    {
   		distancia[i] = A;
    }

    distancia[0] = 0;
    /*queue<int> fila;
    fila.push(0);*/
    j = 0;
    while (j<n)
    {//printf("ola\n" );
        //int u = fila.front();
        //fila.pop();
        for (int i = 0; i < n; i++)
        {
            if ((grafo[j][i] < A) && (distancia[i] > distancia[j] + grafo[j][i]))
            {
               	distancia[i] = distancia[j] + grafo[j][i];
                //fila.push(i);
            }
        }
        j++;
    }
    //printf("ola\n" );
    bool possible = false;
    for (int i = 0; i < n; i++)
        {
        	for (int j = 0; j < n; j++)
        	{
	            if ((grafo[i][j] < A) && (distancia[j] > distancia[i] + grafo[i][j]))
	            {
	               	possible = true;
	               	break;
	            }
        	}
        	if (possible)
        	{
        		break;
        	}
        }
    if(possible)
    	printf("possible\n");
    else
    	printf("not possible\n");	
    //printf("%d\n", distancia[c-1]);
    
}

int main(){
	ios_base::sync_with_stdio(false);
	int test,x, y, t;
	cin>>test;
	while(test>0){
		test--;
		cin>>n>>m;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++)
			{
				grafo[i][j] = A;
			}
		}
		for(int i=0; i<m; i++){
			cin>>x>>y>>t;
			grafo[x][y]=t;	
		}
		
		dijkstra();
		
	}

	return 0;
}