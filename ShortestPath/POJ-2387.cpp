#include<cstdio>

#define MAX 1005
#define TMAX 2005
using namespace std;

int dis[MAX];
int len[MAX][MAX];
int road[TMAX][2];
int count = 0;
int N, T;

void Relax(int u, int v){
	if(dis[u]+len[u][v] < dis[v])
		dis[v] = dis[u] + len[u][v];
}

void BellmanFord(){
	int i, j, k;
	// initialize
	for(i=1; i<N; ++i)
		dis[i] = 999999;
	dis[N] = 0;

	// relax
	for(i=1; i<N; ++i){
		for(j=0; j<count; ++j){
			Relax(road[j][0], road[j][1]);
			Relax(road[j][1], road[j][0]);
		}
	}

}

void setRoad(int x, int y, int w){
	int i, flag=0;
	for(i=0; i<count; ++i){
		if((road[i][0]==x && road[i][1]==y) ||
				(road[i][0]==y && road[i][1]==x)){
			flag = 1;
			if(w < len[x][y]){
				len[x][y] = w;
				len[y][x] = w;
			}
		}
	}

	if(flag == 0){
		road[count][0] = x;
		road[count][1] = y;
		count++;
		len[x][y] = w;
		len[y][x] = w;
	}
}

int main(){

	int i, j;
	int x, y, w;

	scanf("%d%d", &T, &N);

	for(i=0; i<T; ++i){
		scanf("%d%d%d", &x, &y, &w);
		setRoad(x, y, w);
	}

	BellmanFord();

	printf("%d\n", dis[1]);

	return 0;
}
