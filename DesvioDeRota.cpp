#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define A 100000

int grafo[1000][1000];
int distancia[1000], n, m, s, k, c;

void dijkstra()
{
    for (int i = 0; i < n; i++)
    {
   		distancia[i] = A;
    }

    distancia[k] = 0;
    queue<int> fila;
    fila.push(k);

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
    printf("%d\n", distancia[c-1]);
    
}

int main(){
	ios_base::sync_with_stdio(false);
	int  v, p, u;
	while(1){
		cin>>n>>m>>c>>k;
		if (n==0 && m==0 && c==0 && k==0)
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
			cin>>u>>v>>p;
			if(u>=c && v>=c){
				grafo[u][v]=p;	
				grafo[v][u]=p;
			}	
			if(u>=c && v<c) 
				grafo[u][v]=p;
			else{ 
				if(u<c && v>=c) 
					grafo[v][u]=p;
				else{
					if(u<c && v<c && abs(u-v)==1){
						grafo[u][v]=p;
						grafo[v][u]=p;
					}
				}
			} 
		}
		
		dijkstra();
		
	}

	return 0;
}