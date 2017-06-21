#include <stdio.h>
#include <stdlib.h>
#define A 101

int grafo[A][A][A], n, m;

void floyd(){
	
	int k,i,j;
	for (k=0; k<n; k++){
		for (j=0; j<n; j++){
			for (i=0; i<n; i++){
				if(grafo[k][j][i] < grafo[k][j][k] + grafo[k][k][i])
					grafo[k+1][j][i] = grafo[k][j][i];
				else
					grafo[k+1][j][i] = grafo[k][j][k] + grafo[k][k][i];
			}
		}
	}
}

int main(){

	int test = 1, u, v, w, c, i, k, j;

	while(scanf("%d %d", &n, &m) != EOF){

		for (k=0; k<n; k++){
			for (j=0; j<n; j++){
				for (i=0; i<n; i++){
					if (j != i)
						grafo[k][j][i] = 100000;
					else
						grafo[k][j][i] = 0;
				}
			}
		}

		for (i=0; i<m; i++){
			scanf("%d %d %d", &u, &v, &w);
			u--;v--;
			if(grafo[0][u][v] >  w)
				grafo[0][u][v] = w;
		}
		
		floyd();

		scanf("%d", &c);
		int t;

		printf("Instancia %d\n", test++);
		for ( i=0; i<c; i++){
			scanf("%d %d %d", &u, &v, &t);
			u--;v--;
			if (grafo[t][u][v] != 100000)
				printf("%d\n",grafo[t][u][v]);
			else
				printf("-1\n");
		}
		printf("\n");
	}	
	return 0;
}