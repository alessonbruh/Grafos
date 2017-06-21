
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int r, visita[101], fila[101], inicio, fim, menor[101];
int grafo[101][101];

int buscaLargura(int origem, int c){
	int aux, i, dist = 0;
	
	for(i=0; i<c; i++){
		visita[i] = 0;
		menor[i] = 0;
	}
	visita[origem] = 1;
	inicio = 0;
	fim = 0;
	menor[origem] = 0;
	fila[fim++] = origem;
	while(inicio != fim){
		aux = fila[inicio++];
		for(i=0; i<c; i++){
			if((grafo[aux][i] == 1) && (visita[i] == 0)){
				fila[fim++] = i;
				menor[i] = menor[aux] + 1;
				visita[i] = 1;
			}
		}
	}

	for(i=0;i<c;i++){
		if(menor[i] > dist)
			dist = menor[i];
	}

	return dist;

}	


int main(){
	
	
	int i,j,c ,x,y,max, test = 1, result = 5000;
	int salvo;
	
	
	while(1){
		scanf(" %d", &c);

		if(c == 0)
			return 0;
		
		for(i = 0; i < c; i++){
			for(j = 0; j < c; j++)
				grafo[i][j] = 0;	
		}
			
		for(i=0; i<c-1; i++){
			scanf("%d %d", &x, &y);
			grafo[x-1][y-1] = 1;
			grafo[y-1][x-1] = 1;
		}

		for(i=0; i<c; i++){
			max = buscaLargura(i, c);
			if(result>max){
				result = max;
				salvo = i + 1;
			}
		}
		printf("Teste %d\n%d\n", test, salvo);

		result = 5000;
		test++;

	}
	return 0;
}

