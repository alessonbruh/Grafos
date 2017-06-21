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
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
using namespace std;
#define A 50

int test = 1, n;
int grafo[A][A], grau[A];
vector <int>result;

void dfs(int inicio){

	for (int i = 0; i < A; i++)
	{
		while(grafo[inicio][i]>=1){
			grafo[inicio][i]--;
			grafo[i][inicio]--;
			dfs(i);
		}
	}
	result.push_back(inicio);
}

int main(){
	ios_base::sync_with_stdio(false);
	int t, x, y;

	scanf("%d", &t);;
	while(t != 0){
		t--;
		scanf("%d", &n);
		result.clear();
        for (int i = 0; i < A; i++){
           	grau[i] = 0;
           	for (int j = 0; j < A; j++)
               	grafo[i][j] = 0;
        }
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			--x; --y;
			grafo[x][y]++; grafo[y][x]++;
			grau[x]++; grau[y]++;
		}
		int impar = 0;
		for (int i = 0; i < A; i++)
		{
			if(grau[i]%2 != 0){
				impar++;
				break;
			}
		}
		int inicial = 0;
		if(impar == 0){
			while(inicial<A && grau[inicial] == 0){
				inicial++;

			}
			dfs(inicial);
			if (result.size() == n+1){
				printf("Case #%d\n", test++);
				for (int i = 0; i < n; i++)
				{
					printf("%d %d\n", result[i]+1, result[i+1]+1);
				}
				if(t>=1)
					printf("\n");
			}
			else{
				printf("Case #%d\nsome beads may be lost\n", test++);
				if(t>=1)
					printf("\n");
			}
        }
		else{
			printf("Case #%d\nsome beads may be lost\n", test++);
			if(t>=1)
					printf("\n");
		}
	}
	return 0;
}