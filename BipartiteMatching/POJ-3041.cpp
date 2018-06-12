#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 505

using namespace std;

int k, n;
int edge[MAX][MAX];
int rlink[MAX], used[MAX];

bool dfs(int now){
    int next;
    
    // Try all vertices on the right side
    for(next=1; next<=n; ++next){
        
        // Visit once only
        if(edge[now][next]!=0 && !used[next]){
            used[next] = true;
            //int nxt =rlink[next];
            // Unmatched vertex, or augmenting  path found
            if(rlink[next] == 0 || dfs(rlink[next])){
                // Upadte matching
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
    
    memset(rlink, 0, sizeof(rlink));
    
    for(i = 1; i <= n; i++) {
        memset(used, 0, sizeof(used));
        if(dfs(i))
            ans++;
    }
    return ans;
}

int main()
{
    int i, x, y;
    while (scanf("%d %d", &n, &k) != EOF) {
        memset(edge, 0, sizeof(edge));
        
        for (int j = 0; j < k; ++j) {
            scanf("%d %d", &x, &y);
            
            edge[x][y] = 1;
        }
        
        printf("%d\n", BipartiteMatching());
    }
}
