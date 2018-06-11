#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 105
using namespace std;

struct Point{
	float x, y;
};

int n, m, s, v;
int llink[MAX], rlink[MAX];
int used[MAX];
int edge[MAX][MAX];


// Augumenting Path
bool DFS(int now){
	int next;

	// Try all vertices on the right side
	for(next=0; next<m; ++next){
		// Visit once only
		if(edge[now][next]!=0 && !used[next]){
			used[next] = true;
			// Unmatched vertex, or augmenting  path found
			if(rlink[next] == -1 || DFS(rlink[next])){
				// Upadte matching
				llink[now] = next;
				rlink[next] = now;
				return true;
			}
		}
	}
	// No augmenting path is found
	return false;
}

int BipartiteMatching(){
	int ans = 0,i;

	// Numbering from 1 to nL/nR
	memset(llink, -1, (n+1)*sizeof(int));
	memset(rlink, -1, (m+1)*sizeof(int));

	// Try all vertices ont the left side
	for(i=0; i<n; ++i){
		memset(used, false, (m+1)*sizeof(int));
		if(DFS(i)) ans++;
	}

	return ans;

} 

int main (){
	int i, j;
	while(scanf("%d%d%d%d", &n, &m, &s, &v) != EOF){
		Point gopher[MAX], hole[MAX];
		
		// Input gopher position
		for(i=0; i<n; ++i)
			scanf("%f%f", &gopher[i].x, &gopher[i].y);

		// Input hole position
		for(i=0; i<m; ++i)
			scanf("%f%f", &hole[i].x, &hole[i].y);
		
		// distance		
		for(i=0; i<n; ++i){
			for(j=0; j<m; ++j){
				float disx = gopher[i].x - hole[j].x;
				float disy = gopher[i].y - hole[j].y;
				float dis = sqrt(disx*disx + disy*disy);

				if(dis/v <= s) edge[i][j] = true;
				else edge[i][j] = false;
			}
		}

		// Bipartite Matching
		printf("%d\n", n - BipartiteMatching());

	}

}
