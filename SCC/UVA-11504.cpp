#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>

#define MAX 100005

using namespace std;

vector<vector<int> > adj(MAX);
vector<int> visit(MAX, false);
vector<int> finish;
//int scc[MAX];
int N;


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
	int i;
//	printf("cur %d cnt %d\n", cur, cnt);
//	scc[cur] = cnt;

	visit[cur] = 1;
	for(i = 0; i< adj[cur].size(); ++i){
		if(!visit[adj[cur][i]]){
//			printf("v %d\n", i);
			DFS2(adj[cur][i]);
		}
	}
}

int main(){

	int i, j;
	int n, m, x, y;
	int cases;
	scanf("%d", &cases);

	while(cases--){
		int ans = 0;
		scanf("%d%d", &N, &m);

		finish.clear();
		visit.assign(N+1, 0);
		for(i=0;i<=N;++i){
			adj[i].clear();
		}

		for(i=0; i<m; ++i){
			scanf("%d%d", &x, &y);
			adj[x].push_back(y);
//			adj[y][x] = 1;
		}

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
	
		printf("%d\n", ans);
	}


	return 0;
}
