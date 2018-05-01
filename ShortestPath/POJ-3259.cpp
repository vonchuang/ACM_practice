#include<cstdio>

#define MAX 1005
#define TMAX 6000
#define INF 999999
using namespace std;

int dis[MAX];
int len[MAX][MAX];
int road[TMAX][2];
int count = 0;
int F, N, M, W, S, E, T;

void Relax(int u, int v){
	if(dis[u]+len[u][v] < dis[v])
		dis[v] = dis[u] + len[u][v];
}

bool BellmanFord(){
	int i, j, k;
	// initialize
	for(i=1; i<=N; ++i)
		dis[i] = INF;
	dis[1] = 0;

	// relax
	for(i=1; i<N; ++i){
		for(j=0; j<count; ++j){
			Relax(road[j][0], road[j][1]);
		}
	}

	// negative Cycle
	for(j=0; j<count; ++j){
		int u = road[j][0];
		int v = road[j][1];
		if(dis[u]+len[u][v] < dis[v]){
			return true;
		}
	}
	return false;
}

void setRoad(int x, int y, int w){
	int i, flag=0, j;

	for(i=0; i<count; ++i){
		if(road[i][0]==x && road[i][1]==y){
			flag = 1;
			if(w < len[x][y]){
				len[x][y] = w;
			}
		}
	}

	if(flag == 0){
		road[count][0] = x;
		road[count][1] = y;
		count++;
		len[x][y] = w;
	}
}

int main(){

	int i, j;

	while(scanf("%d", &F) == 1){
		while(F--){
			// initialize
			count = 0;
			for(i=0;i<=N;++i){
				for(j=0;j<=N;++j){
					len[i][j] = 0;
				}
				road[i][0] = 0;
				road[i][1] = 0;
			}

			// input
			scanf("%d%d%d", &N, &M, &W);
	
			for(i=0; i<M; ++i){
				scanf("%d%d%d", &S, &E, &T);
				setRoad(S, E, T);
				setRoad(E, S, T);
			}

			for(i=0; i<W; ++i){
				scanf("%d%d%d", &S, &E, &T);
				setRoad(S, E, -T);
			}
			
			if(BellmanFord())
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}
