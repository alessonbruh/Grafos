#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <cstdio>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int i, j,a,b, n, m, cont, aux;
    set<int>top;

        cin>>n>>m;
        vector<int> grafo[n];
        vector<int>vetor;

        int prioridade[n];
        memset(prioridade, 0, sizeof(prioridade[0]) *n);

        for(i=0; i<m;i++){
            cin>>a>>b;
            grafo[a].push_back(b);
            prioridade[b] = prioridade[b]+1;
        }

        for(i=0;i<n;i++){
            if(prioridade[i] == 0)
                top.insert(i);
        }

        for(i = n-1;!(top.empty());i--){
              aux = *(top.begin());
              cont = grafo[aux].size();
              top.erase(top.begin());

              for(j=0; j<cont;j++){
                        prioridade[grafo[aux][j]]--;
                        if(prioridade[grafo[aux][j]] == 0){
                            top.insert(grafo[aux][j]);
                        }
              }
              vetor.push_back(aux);
        }
        if(i<0){
            for(int i=0;i<n;i++)
			     printf("%d\n", vetor[i]);
        }
        else
            printf("*\n");

    return 0;

}
