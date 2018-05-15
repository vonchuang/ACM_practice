#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX 10005

using namespace std;

const int V = MAX;
const int E = MAX*(MAX-1)/2;
int N, C, M;
int cnt;
int result;

struct Edge{
	int s;
	int f;
	int w;
}edge[E];

int p[V];

bool operator<(Edge e1, Edge e2){
	return e1.w > e2.w;
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
	int check = 0;
	sort(edge, edge+M);

//	printf("cnt: %d\n", cnt);
	for(i=0; i<M; ++i){
		if(Find(edge[i].s) != Find(edge[i].f)){
//			printf("j %d\n", j);
			
		
//			printf("%d res + %.2lf", j, edge[j].w);
//			printf("%d %d\n", edge[j].s, edge[j].f);
			Union(edge[i].s, edge[i].f);
//			result += edge[j].w;
			check++;
			result = edge[i].w;
		
		}
	}

}

int main(){
	int i, j;

	scanf("%d", &C);
	for(j=1; j<=C; ++j){
		
		int s, f, w;


		scanf("%d%d", &N, &M);
		for(i=0; i<=N; ++i){
			p[i] = i;
		}

		// calc weight
		
		for(i=0; i<M; ++i){
			scanf("%d%d%d", &edge[i].s, &edge[i].f, &edge[i].w);
			cnt++;
//			printf("(%d %d %lf)\n", i, j, edge[cnt-1].w);
			
		}

		result = 0;
		Kruskal();


		printf("Case #%d: %d\n", j, result);
		
	}

	return 0;
}
