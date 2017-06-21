#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int n;
string nome[32];

int buscaNome(string no){
    int i;

    for(i=0;i<n;i++){
        //cout<<nome[i]<<"    "<<no;
        if(nome[i] == no){
            return i;
        }
    }
    return 0;
}

int main(){
    int i, j,ind, in, num, vetorNum[32], contador, aux, test = 1;
    string nomeAux;
    std::queue <int> fila;

    while(1){
        cin>>n;
        if(n == 0)
            return 0;
        int grafo[n][n], result[n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                grafo[i][j] = 0;
            }
        }
        for(i=0; i<n;i++){
            cin>>nome[i];
            vetorNum[i]=0;
        }
        //for(i=0;i<n;i++)
          //  cout<<nome[i];
        for(i=0; i<n;i++){
            cin>>nomeAux>>num;
            ind = buscaNome(nomeAux);
            vetorNum[ind] = num;

            for(j=0;j<num;j++){
                cin>>nomeAux;
                in = buscaNome(nomeAux);
                grafo[in][ind] = 1;
            }

        }
        /*for(i=0;i<n;i++)
            printf("%d    ", vetorNum[i]);*/
        for(i=0;i<n;i++){
            if(vetorNum[i]==0){
                fila.push(i);
                vetorNum[i] = -1;
            }
        }
        contador = 0;

        while(!(fila.empty())){
              aux = fila.front();
              result[contador] = aux;
              fila.pop();
              contador++;
              for(i=0; i<n;i++){
                    if(grafo[aux][i] ==1){
                        vetorNum[i]--;
                    }
              }

              for(i=0;i<n;i++){
                    if(vetorNum[i] == 0){
                        fila.push(i);
                        vetorNum[i]=-1;
                    }
              }
        }
        printf("Teste %d\n", test++);
        if (contador != n)
            printf("impossivel\n\n");
        else
        {
            for (i=0; i<n; i++)
                cout<<nome[result[i]]<<" ";
            printf("\n\n");
        }

    }
}
