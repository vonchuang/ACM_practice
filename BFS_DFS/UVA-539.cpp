#include<cstdio>
#include<queue>

#define MAX 25

using namespace std;

int list[MAX][MAX];
int vis[MAX][MAX];
int result = 0;
int n, m;

void DFS(int cur, int depth){
	int i, j;
	
	if(depth > result)
		result = depth;
	for(i=0; i<n; ++i){
		if(vis[cur][i] == 0 && list[cur][i] == 1){
			vis[cur][i] = depth + 1;
			vis[i][cur] = depth + 1;
			
			//printf("%d -> %d(%d)\n", cur, i, vis[cur][i]);
			DFS(i, depth + 1);
			vis[cur][i] = 0;	// important!!
			vis[i][cur] = 0;
		}
	}

}

int main(){

	int a, b;
	int i, j, k;

	for(i=0; i<MAX; ++i)
		for(j=0; j<MAX; ++j){
			list[i][j] = 0;
			vis[i][j] = 0;
		}

	scanf("%d %d", &n, &m);

	while(!(n == 0 && m == 0)){
		// scan input
		for(i=0; i<m; ++i){
			scanf("%d %d", &a, &b);
			list[a][b] = 1;
			list[b][a] = 1;
		}

		// BFS
		for(i=0; i<n; ++i){
			DFS(i, 0);
		}

		// print result
		printf("%d\n", result);

		// initialize
		result = 0;	
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				list[i][j] = 0;
				vis[i][j] = 0;
			}
		}
		
		scanf("%d %d", &n, &m);
	}


	return 0;
}
