#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define V 52
int grafo[101][101], m;
int n;
int visita[101], fila[101], inicio, fim, pai[101];

int buscaLargura(int origem, int t){
	int aux, i, dist = 0;
	
	for(i=0; i<V; i++){
		visita[i] = 0;
	}

	visita[origem] = 1;
	pai[origem] = -1;
	inicio = 0;
	fim = 0;
	fila[fim++] = origem;
	while(inicio != fim){
		aux = fila[inicio++];
		for(i=0; i<V; i++){
			if((grafo[aux][i] > 0) && (visita[i] == 0)){
				fila[fim++] = i;
				pai[i] = aux;
				visita[i] = 1;
			}
		}
	}

	return visita[t];

}		

void Fulkerson(int s, int t)
{
	int u, v;
	 

	int fluxoMax = 0; 
	while (buscaLargura( s, t) == 1)
	{
		int fluxo = 100000;
		for (v=t; v!=s; v=pai[v])
		{
			u = pai[v];
			if(fluxo > grafo[u][v])
				fluxo = grafo[u][v];
		}

		for (v=t; v != s; v=pai[v])
		{
			u = pai[v];
			grafo[u][v] -= fluxo;
			grafo[v][u] += fluxo;
		}

		fluxoMax = fluxoMax + fluxo;
	}

	if(fluxoMax == m)
		printf("YES\n");
	else
		printf("NO\n"); 
}


int convert(char size[4]) {
    if (strcmp(size, "XS") == 0)
        return 1;
    if (strcmp(size, "S") == 0)
        return 2;
    if (strcmp(size, "M") == 0)
        return 3;
    if (strcmp(size, "L") == 0)
        return 4;
    if (strcmp(size, "XL") == 0)
        return 5;
    if (strcmp(size, "XXL") == 0)
        return 6;
    return -1;
}

int main()
{
	int f;
	char a[4], b[4];
	int teste;
	cin>>teste;
	while(teste != 0){
		teste--;
		cin>>n>>m;
		//memset(grafo, 0, sizeof grafo);
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				grafo[i][j] = 0;

			}
			pai[i] = 0;
		}
		//	construir s
		for (int i = 1; i <= 6; i++) {
			grafo[0][i] = n / 6;
		}

		// voluntarios
		for (int i = 7; i < 7 + m; i++) {
			grafo[i][7 + m] = 1;
		}

		for (int i = 7; i< 7+m; i++)
		{
			cin>>a>>b;
			grafo[ convert(a) ][i] = 1;
			grafo[ convert(b) ][i] = 1;

		}

		Fulkerson(0, m + 7);
	}
	return 0;
}
