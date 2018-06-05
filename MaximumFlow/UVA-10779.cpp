#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 205
#define INF 1000006

using namespace std;

int N, M, C, Sup, T;
int vis[MAX], pa[MAX], neck[MAX];
int cap[MAX][MAX], flow[MAX][MAX];

bool DFS(int cur, int t, int n){
	int i, j, k;
	
	vis[cur] = 1;

	if(cur == t)	return true;
	for(i=1; i<=t; ++i){
		if(vis[i])	continue;
		if(neck[i] == 0 && (cap[cur][i] - flow[cur][i])>0){
			pa[i] = cur;
			neck[i] = min(neck[cur], cap[cur][i] - flow[cur][i]);
			if(DFS(i, t, n))	return true;
		}
	}
	return false;

	return 1;
}

void FindFlow(){
	int i;

	for(i=Sup; i!=1; i=pa[i]){
		int pre = pa[i];
		flow[pre][i] += neck[Sup];
		flow[i][pre] -= neck[Sup];
	}
}

int FordFulkerson(int n){
	int i, j, k;
	int ret = 0;

	while(1){
		memset(vis, 0, sizeof(vis));
		memset(neck, 0, sizeof(neck));
		neck[1] = INF;
		DFS(1, Sup, n);
		if(neck[Sup] == 0)	break;

		FindFlow();
		ret += neck[Sup];	

	}	
	return ret;
}

int main(){
	int i, j, k, K, ki;
	int a, b, len;
	int Case = 1;

	scanf("%d", &C);

	while(C--){
		memset(flow, 0, sizeof(flow));
		memset(cap, 0, sizeof(cap));

		scanf("%d%d", &N, &M);
		T = N+M+1;

		for(i=1; i<=N; ++i){
			scanf("%d", &k);
			for(j=0; j<k; ++j){
				scanf("%d", &ki);
				cap[i][N+ki]++;
			}
		}
        for (int i = 2; i <= N; ++i) {
            for (int j = N+1; j <= N+M; ++j) {
                if (cap[i][j]) cap[i][j]--;  
                else cap[j][i] = 1;       
            }
        }
        for (int i = N+1; i <= N+M; ++i)    
            cap[i][T] = 1;

		Sup = N+M+1;
		int res = FordFulkerson(N);

		printf("Case #%d: %d\n", Case, res);
		
		Case++;
	}

	return 0;
}

