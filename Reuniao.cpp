#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define A 100000

int grafo[1000][1000];
int distancia[1000], n, m, s, d;

void dijkstra(int ori)
{
    for (int i = 0; i < n; i++)
    {
   		distancia[i] = A;
    }

    distancia[ori] = 0;
    queue<int> fila;
    fila.push(ori);

    while (!fila.empty())
    {
        int u = fila.front();
        fila.pop();
        for (int i = 0; i < n; i++)
        {
            if ((grafo[u][i] < A) && (distancia[i] > distancia[u] + grafo[u][i]))
            {
               	distancia[i] = distancia[u] + grafo[u][i];
                
                fila.push(i);
            }
        }
    }
    /*if( distancia[d] != A)
			printf("%d\n", distancia[d]);
		else
			printf("-1\n");*/
    //return distancia[d];
}

int main(){
	ios_base::sync_with_stdio(false);
	int c, v, t;
	//while(1){
		cin>>n>>m;
		if (n==0 && m==0)
		{
			return 0;
		}
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++)
			{
				grafo[i][j] = A;
			}
		}
		for(int i=0; i<m; i++){
			cin>>t>>v>>c;
			grafo[t][v] = c;
			grafo[v][t] = c;
		}
		int menor = A;
		for (int i = 0; i < n; i++)
		{	
			dijkstra(i);
			int max = 0;
			for (int j = 0; j < n; j++) 
           	 	if (max < distancia[j]) 
           	 		max = distancia[j]; 
         	if (max < menor) 
         		menor = max; 
      	} 	
      	printf("%d\n",menor );				
	//}

	return 0;
}