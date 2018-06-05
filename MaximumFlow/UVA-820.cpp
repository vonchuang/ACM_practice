#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 205
#define INF 1000006

using namespace std;

int N, S, T, C;
int vis[MAX], pa[MAX], neck[MAX];
int cap[MAX][MAX], flow[MAX][MAX];

bool DFS(int cur, int t, int n){
	int i, j, k;
	
	vis[cur] = 1;

	if(cur == t)	return true;
	for(i=1; i<=n; ++i){
		if(vis[i])	continue;
		if(neck[i] == 0 && (cap[cur][i] - flow[cur][i])>0){
			pa[i] = cur;
			neck[i] = min(neck[cur], cap[cur][i] - flow[cur][i]);
			if(DFS(i, t, n))	return true;
		}
	}
	return false;

/*
    queue<int> Q;
    Q.push(S);

    while (!Q.empty() && neck[T] == 0) {
        int cur = Q.front(); 
		int i;
		Q.pop();
        for (i = 1; i <= N; ++i) {
            if (neck[i] == 0 && cap[cur][i] > flow[cur][i]) {
                Q.push(i);
                pa[i] = cur;
                neck[i] = min(neck[cur], cap[cur][i] - flow[cur][i]);
            }
        }
    }
*/
	return 1;
}

void FindFlow(){
	int i;

	for(i=T; i!=S; i=pa[i]){
		int pre = pa[i];
		flow[pre][i] += neck[T];
		flow[i][pre] -= neck[T];
	}
}

int FordFulkerson(int n){
	int i, j, k;
	int ret = 0;

	while(1){
		memset(vis, 0, sizeof(vis));
		memset(neck, 0, sizeof(neck));
		neck[S] = INF;
		//if(!DFS(1, n, n))	break;
		DFS(S, T, n);
		if(neck[T] == 0)	break;

		FindFlow();
		ret += neck[T];	

	}	
	return ret;
}

int main(){
	int i, j, k;
	int a, b, len;
	int Case = 1;

	scanf("%d", &N);

	while(N != 0){
		memset(flow, 0, sizeof(flow));
		memset(cap, 0, sizeof(cap));

		scanf("%d%d%d", &S, &T, &C);
		
		for(i=0; i<C; ++i){
			scanf("%d %d %d", &a, &b, &len);
			cap[a][b] += len;
			cap[b][a] += len;
		}

		int res = FordFulkerson(N);

		printf("Network %d\n", Case);
		printf("The bandwidth is %d.\n\n", res);
		
		Case++;
		scanf("%d", &N);

	}

	return 0;
}

