#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX 1000005

using namespace std;

const int V = MAX;
const int E = MAX;
int N, T, K, M;
int cnt;
int result;
int indexcon;

struct Edge{
	int s;
	int f;
	int w;
}edge[E];

int p[V];

bool operator<(Edge e1, Edge e2){
	return e1.w < e2.w;
}

int Find(int x){
	if(x == p[x])
		return x;
	else
		return p[x] = Find(p[x]);
}

void Union(int x, int y){
	p[Find(x)] = Find(y);
}

void Kruskal(){
	int i, j;

	sort(edge, edge+cnt);

//	printf("cnt: %d\n", cnt);
	for(i=1, j=0; i<N && j<cnt; ++i){
		while(Find(edge[j].s) == Find(edge[j].f)){
//			printf("j %d\n", j);
			j++;
		}
		if(j < cnt){
//			printf("%d res + %.2lf", j, edge[j].w);
//			printf("%d %d\n", edge[j].s, edge[j].f);
			indexcon++;
			Union(edge[j].s, edge[j].f);
			result += edge[j].w;

			j++;
		}
	}

}

int main(){
	

	int flag = 0;
	while(scanf("%d", &N) != EOF){
		int i, j;
		int s, f, w;
		int org = 0;

		for(i=1; i<N; ++i){
			scanf("%d%d%d", &s, &f, &w);
			org += w;
		}

		for(i=1; i<=N; ++i){
			p[i] = i;
		}

		// calc weight
		cnt = 0;
		// new edge
		scanf("%d", &K);
		for(i=1; i<=K; ++i){
			scanf("%d%d%d", &edge[cnt].s, &edge[cnt].f, &edge[cnt].w);
			cnt++;
//			printf("(%d %d %lf)\n", i, j, edge[cnt-1].w);
			
		}

		// org edge
		scanf("%d", &M);
		for(i=1; i<=M; ++i){
			scanf("%d%d%d", &edge[cnt].s, &edge[cnt].f, &edge[cnt].w);
			cnt++;
//			printf("(%d %d %lf)\n", i, j, edge[cnt-1].w);
			
		}


		result = 0;
		indexcon = 0;
		Kruskal();


		if(flag != 0)
			printf("\n");
		printf("%d\n", org);
		printf("%d\n", result);
		
		flag = 1;
	}

	return 0;
}
