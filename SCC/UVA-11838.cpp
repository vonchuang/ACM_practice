#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>

#define MAX 2005

using namespace std;

vector<vector<int> > adj(MAX);
vector<int> visit(MAX, false);
vector<int> finish;
//int scc[MAX];
int N, M;


void DFS(int cur){
	int i;

	visit[cur] = 1;

	for(i = 0; i < adj[cur].size(); ++i){
		if(!visit[adj[cur][i]]){
			DFS(adj[cur][i]);
		}	
	}

//	printf("push %d\n", cur);
	finish.push_back(cur);

}

void DFS2(int cur){
	int i, j;
//	printf("cur %d\n", cur);
//	scc[cur] = cnt;

	visit[cur] = 1;
	for(i = 1; i<=N; ++i){
		for(j=0;j<adj[i].size();++j){
			if(adj[i][j] == cur && !visit[i]){
//				printf("%d v %d\n",cur, i);
				DFS2(i);
			}
		}
	}
}

int main(){

	int i, j;
	int v, w, p;

	scanf("%d%d", &N, &M);
	while(!(N==0 && M==0)){
		int ans = 0;

		finish.clear();
		visit.assign(N+1, 0);
		for(i=0;i<=N;++i){
			adj[i].clear();
		}

		for(i=0; i<M; ++i){
			scanf("%d%d%d", &v, &w, &p);
			adj[v].push_back(w);
//			printf("(%d %d)", v, w);
			if(p == 2){
				adj[w].push_back(v);
//				printf("(%d %d)", w, v);
			}
		}
/*		
		for(i=1;i<=N;++i){
			for(j=0;j<adj[i].size();++j){
				printf("%d %d\n", i, adj[i][j]);
			}
		}
*/
		for(i=1; i<=N; ++i){
			if(!visit[i]){
				DFS(i);
			}
		}


		visit.assign(N+1, 0);
		
		for(i=N-1; i>=0; --i){
			if(!visit[finish[i]]){
//				printf("vis %d\n", finish[i]);
				DFS2(finish[i]);
				ans++;
			}
		}

		if(ans == 1)
			printf("1\n");
		else
			printf("0\n");
		
		scanf("%d%d", &N, &M);
	}


	return 0;
}
