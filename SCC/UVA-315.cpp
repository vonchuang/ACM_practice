#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<sstream>

#define MAX 105

using namespace std;

int adj[MAX][MAX];
int visit[MAX];
int low[MAX];
int t = 0;
int child = 0;
int N;
int ans = 0;

void DFS(int prev, int cur){
	bool cut = false;
	int child = 0;
	int idx;

	visit[cur] = ++t;
	low[cur] = t;

	for(idx = 1; idx <= N; ++idx){
		if(adj[cur][idx] && idx != prev){
			if(visit[idx]){
				low[cur] = min(low[cur], visit[idx]);
			}else{
				child++;
				DFS(cur, idx);

				low[cur] = min(low[cur], low[idx]);
				if(low[idx] >= visit[cur]){
					cut = true;
				}
			}
		}
	
	}

	if((child >= 2 || prev != -1) && cut){
		++ans;
		//printf("%d\n", cur);
	}


}

int main(){

	int i, j;
	scanf("%d", &N);

	while(N != 0){
		string line;
		int a, b;
		char enter;
		scanf("%c", &enter);

		for(i=0; i<=N; ++i){
			for(j=0; j<=N; ++j){
				adj[i][j] = 0;
			}
			visit[i] = 0;
			low[i] = 0;
		}
		t = 0;
		child = 0;
		ans = 0;

		while(getline(cin, line)){
			int index = 0;
			int input[MAX] = {0};
			stringstream num(line);
			num >> a;
			if(!a) break;
			while(num >> b){
				input[index++] = b;
			}

			for(i=0; i<index; ++i){
//				printf("%d ", input[i]);
				adj[a][input[i]] = 1;
				adj[input[i]][a] = 1;
			}
//			printf("\n");
		}
			

		DFS(-1, 1);
		printf("%d\n", ans);
		scanf("%d", &N);
	}

	return 0;
}
