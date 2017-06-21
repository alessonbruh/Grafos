#include <stdio.h>
#include <stdlib.h>

#define A 200
#define B 802

int p, t, s, c;
int pessoas[B], taxi[B];
int grafo[B][B], visita[B], salvaVert[B], result;


int buscaLargura(int aux){
	int i, dist = 0;
	

	/*visita[origem] = 1;
	pai[origem] = -1;
	inicio = 0;
	fim = 0;
	fila[fim++] = origem;
	while(inicio != fim){*/
		i=0;
		while(i<t*2){
			if((grafo[aux][i] != 0) && (visita[i] == 0)){
				visita[i] = 1;
				if (salvaVert[i]<0 || buscaLargura(salvaVert[i]) == 1)
				{
					salvaVert[i]=aux;
					return 1;
				}
				/*fila[fim++] = i;
				pai[i] = aux;*/
			}
		i=i+2;
		}
	//}
	return 0;
	//return visita[t];
}


int main()
{
	int test;
	int distancia;

	scanf("%d", &test);
	while(test > 0){
		test--;
		scanf("%d %d %d %d", &p, &t, &s, &c);

		for (int i = 0; i < B; i++)
		{
			for (int j = 0; j < B; j++)
			{
				grafo[i][j] = 0;
			}
			pessoas[i] = 0;
			taxi[i] = 0;
			salvaVert[i] = -1;
		}

		for (int i = 0; i < p*2; i=i+2)
			scanf("%d %d", &pessoas[i], &pessoas[i+1]);
		
		for (int i = 0; i < t*2; i=i+2)
			scanf("%d %d", &taxi[i], &taxi[i+1]);
		
		for (int i = 0; i < p*2; i=i+2)
		{
			for (int j = 0; j < t*2; j=j+2)
			{
				int aux = taxi[j] - pessoas[i];
				if (aux < 0)
					aux = aux*-1;
				int aux2 = taxi[j+1] - pessoas[i+1];
				if (aux2 < 0)
					aux2 = aux2*-1;
				//printf("%d\n", aux2);
				distancia = aux + aux2;
				if ((distancia*A) <= (s*c))
				{
					grafo[i][j] = 1;
				}
			}
		}
		
		result =0;

		for (int i = 0; i < p*2; i=i+2)
		{
			for(int j=0; j<B; j++)
				visita[j] = 0;

			if (buscaLargura(i) == 1)
				result++;
		}
		printf("%d\n", result);;

	}
	
	
	return 0;
}