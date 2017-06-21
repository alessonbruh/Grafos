#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define V 52
int grafo[101][101];
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

	printf("%d\n", fluxoMax); 
}

int transform(char a){
	switch(a){
		case 'A':
			return 0;
		case 'B':
			return 1;
		case 'C':
			return 2;
		case 'D':
			return 3;
		case 'E':
			return 4;
		case 'F':
			return 5;
		case 'G':
			return 6;
		case 'H':
			return 7;
		case 'I':
			return 8;
		case 'J':
			return 9;
		case 'K':
			return 10;
		case 'L':
			return 11;
		case 'M':
			return 12;
		case 'N':
			return 13;
		case 'O':
			return 14;
		case 'P':
			return 15;
		case 'Q':
			return 16;
		case 'R':
			return 17;
		case 'S':
			return 18;
		case 'T':
			return 19;
		case 'U':
			return 20;
		case 'V':
			return 21;
		case 'W':
			return 22;
		case 'X':
			return 23;
		case 'Y':
			return 24;
		case 'Z':
			return 25;
		case 'a':
			return 26;
		case 'b':
			return 27;
		case 'c':
			return 28;
		case 'd':
			return 29;
		case 'e':
			return 30;
		case 'f':
			return 31;
		case 'g':
			return 32;
		case 'h':
			return 33;
		case 'i':
			return 34;
		case 'j':
			return 35;
		case 'k':
			return 36;
		case 'l':
			return 37;
		case 'm':
			return 38;
		case 'n':
			return 39;
		case 'o':
			return 40;
		case 'p':
			return 41;
		case 'q':
			return 42;
		case 'r':
			return 43;
		case 's':
			return 44;
		case 't':
			return 45;
		case 'u':
			return 46;
		case 'v':
			return 47;
		case 'w':
			return 48;
		case 'x':
			return 49;
		case 'y':
			return 50;
		case 'z':
			return 51;
	}
}

int main()
{
	int f;
	char a, b;
	cin>>n;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			grafo[i][j] = 0;
		}
	}

	int u, v;
	for (int i = 0; i < n; i++)
	{
		cin>>a>>b>>f;
		grafo[transform(a)][transform(b)] += f;
	}

	Fulkerson(0, 25);

	return 0;
}
