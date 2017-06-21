#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define A 101

vector<pair <int, pair <int, int> > > grafo;
int arvore[A], n, m, arvore2[A];

void kruskal(){

	int i;
	for (i = 0; i <grafo.size(); i++)
	{

		if( arvore[grafo[i].second.first-1] != arvore[grafo[i].second.second-1]){
			for (int j = 0; j < n; j++)
			{
				if(arvore2[j] == grafo[i].second.first ){
					int x = arvore[j];
					for (int p = 0; p < n; p++)
					{
						if(arvore[p] == x){
							arvore[p] = arvore[grafo[i].second.second-1];
						}
					}
					break;
				}
			}
			
			if(grafo[i].second.first < grafo[i].second.second)
				printf("%d %d\n", grafo[i].second.first, grafo[i].second.second);
			else
				printf("%d %d\n", grafo[i].second.second, grafo[i].second.first);
		}
	}
}

int main(){
	int c, u, v, i, teste = 1;
	while(1){
		cin>>n>>m;

		if(n == 0 && m == 0)
			break;

		for (i = 0; i < n; i++)
			arvore[i+1] = 0;

		for(i=0; i<m; i++){
			cin>>u>>v>>c;
			grafo.push_back(make_pair(c, make_pair(u, v)));
			arvore[u-1] = arvore2[u-1] = u;
			arvore[v-1] = arvore2[v-1] = v;
		}

		sort(grafo.begin(), grafo.end());
		printf("Teste %d\n", teste);
		kruskal();
		printf("\n");
		teste++;
		grafo.clear();
	}
	//printf("%d\n", kruskal());



	return 0;
}