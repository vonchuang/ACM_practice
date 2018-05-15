#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX 1005

using namespace std;

const int V = MAX;
const int E = MAX*(MAX-1)/2;
int N, S, P;
int cnt;
double result;
int indexcon;

struct Edge{
	int s;
	int f;
	double w;
}edge[E];

struct Node{
	int id;
	int x;
	int y;
}p[V];

bool operator<(Edge e1, Edge e2){
	return e1.w < e2.w;
}

int Find(int x){
	if(x == p[x].id)
		return x;
	else
		return p[x].id = Find(p[x].id);
}

void Union(int x, int y){
	p[Find(x)].id = Find(y);
}

void Kruskal(){
	int i, j;

	sort(edge, edge+cnt);

//	printf("cnt: %d\n", cnt);
	for(i=1, j=0; i<S && j<cnt; ++i){
		while(Find(edge[j].s) == Find(edge[j].f)){
//			printf("j %d\n", j);
			j++;
		}
		if(j < cnt){
//			printf("%d res + %.2lf", j, edge[j].w);
			printf("%d %d\n", edge[j].s, edge[j].f);
			indexcon++;
			Union(edge[j].s, edge[j].f);
			result += edge[j].w;

			j++;
		}
	}

}

int main(){
	scanf("%d", &N);

	while(N--){
		int i, j;


		scanf("%d", &S);

		// input point
		for(i=1; i<=S; ++i){
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].id = i;
		}

		// calc weight
		cnt = 0;
		for(i=1; i<=S; ++i){
			for(j=i+1; j<=S; ++j){
				edge[cnt].s = i;
				edge[cnt].f = j;
				edge[cnt++].w = sqrt(pow(abs(p[i].x - p[j].x), 2) + pow(abs(p[i].y - p[j].y), 2));
//				printf("(%d %d %lf)\n", i, j, edge[cnt-1].w);
			}
		}

		scanf("%d", &P);
		for(i=0; i<P; ++i){
			int x, y;
			scanf("%d%d", &x, &y);
			Union(x, y);
		}

		result = 0;
		indexcon = 0;
		Kruskal();

		if(indexcon == 0)
			printf("No new highways need\n");

		if(N > 0)
			printf("\n");
		
	}

	return 0;
}
