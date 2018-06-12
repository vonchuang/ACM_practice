#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 205

using namespace std;

int k, n, m;
int edge[MAX][MAX];
int llink[MAX], rlink[MAX], used[MAX];

bool dfs(int now){
    int next;
    
    // Try all vertices on the right side
    for(next=0; next<m; ++next){
        
        // Visit once only
        if(edge[now][next]!=0 && !used[next]){
            used[next] = true;
            // Unmatched vertex, or augmenting  path found
            if(rlink[next] == -1 || dfs(rlink[next])){
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
    memset(llink, -1, sizeof(llink));
    memset(rlink, -1, sizeof(rlink));
    
    // Try all vertices ont the left side
    for(i = 0; i < n; i++) {
        //if(!llink[i]) {
        memset(used, 0, sizeof(used));
        if(dfs(i))
            ans++;
        //}
    }
    return ans;
}

int main()
{
    int i, x, y;
    while (scanf("%d", &n) && n) {
        memset(edge, 0, sizeof(edge));
        
        scanf("%d %d", &m, &k);
        
        for (int j = 0; j < k; ++j) {
            scanf("%d %d %d", &i, &x, &y);
            if (x==0 || y==0) continue;
            edge[x][y] = 1;
        }
        
        printf("%d\n", BipartiteMatching());
    }
}
