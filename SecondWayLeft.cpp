#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define A 100

vector<pair <int, pair <int, int> > > grafo;
vector<pair <int, pair <int, int> > > aux;
int arvore[A], v, e, arvore2[A], id[A];

int kruskal2(int corte){

	int i, result = 0, cont = 0;
	for (i = 0; i <grafo.size(); i++)
	{

		if( ((i != corte) && arvore[grafo[i].second.first-1] != arvore[grafo[i].second.second-1])){
			for (int j = 0; j < v; j++)
			{
				if(arvore2[j] == grafo[i].second.first ){
					cont++;
					//aux.push_back(make_pair(grafo[i].first, make_pair(grafo[i].second.first, grafo[i].second.second)));
					int x = arvore[j];
					for (int p = 0; p < v; p++)
					{
						if(arvore[p] == x){
							arvore[p] = arvore[grafo[i].second.second-1];
						}
					}
					break;
				}
			}
			result = result + grafo[i].first;
		}
	}
	if(cont == v-1)
		return result;
	return -1;
}


int kruskal(){

	int i, result = 0, cont = 0;
	for (i = 0; i <grafo.size(); i++)
	{

		if( arvore[grafo[i].second.first-1] != arvore[grafo[i].second.second-1]){
			for (int j = 0; j < v; j++)
			{
				if(arvore2[j] == grafo[i].second.first ){
					cont++;
					aux.push_back(make_pair(grafo[i].first, make_pair(grafo[i].second.first, grafo[i].second.second)));
					id[aux.size()-1] = i;
					int x = arvore[j];
					for (int p = 0; p < v; p++)
					{
						if(arvore[p] == x){
							arvore[p] = arvore[grafo[i].second.second-1];
						}
					}
					break;
				}
			}
			result = result + grafo[i].first;
		}
	}
	if(cont == v-1)
		return result;
	return -1;
	
}

int main(){
	int c, teste = 1, t, start, end, cost, mst2, mst1;

	cin>>t;
	while(t>0){
		t--;
		cin>>v>>e;
		grafo.clear(); aux.clear();
		/*for (int i = 0; i < v; i++)
			arvore[i] = 0;*/
		for(int i=0; i<e; i++){
			cin>>start>>end>>cost;
			grafo.push_back(make_pair(cost, make_pair(start, end)));
			arvore[start-1] = arvore2[start-1] = start;
			arvore[end-1] = arvore2[end-1] = end;
		}
		/*if(e==0){
			printf("Case #%d : No second way\n",teste++);			
			continue;
		}*/

		sort(grafo.begin(), grafo.end());
		mst1 = kruskal();
		//sort(aux.begin(), aux.end());
		if(mst1 != -1){
			mst2= -1;
			int temp;
			for (int i = 0; i < aux.size(); i++)
			{
				for (int j = 0; j < v; j++)
				{
					arvore[j] = arvore2[j];
				}
				temp=kruskal2(id[i]);
				if((temp != -1 && mst2 >= temp) || mst2 == -1){
					mst2=temp;
				}
			}
			if(mst2!=-1){
				printf("Case #%d : %d\n", teste++,mst2);
			}else{
				printf("Case #%d : No second way\n", teste++);
			}
		}else{
			printf("Case #%d : No way\n", teste++);
		}
		
	}

	return 0;
}