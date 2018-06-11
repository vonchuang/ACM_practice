#include <cstdio>
#include <cstring>
#include <cmath>

#define MAX 205

using namespace std;

int k, n, m;
int edge[MAX][MAX];
int llink[MAX], rlink[MAX], used[MAX];

// Augumenting Path
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

float dist(int x1, int y1, int x2, int y2){
    int disx = x1 - x2;
    int disy = y1 - y2;
    return sqrt(disx*disx + disy*disy);
}

int main() {
    int i, j, x, y;
    
    scanf("%d", &n);
    while(n != 0) {
        
        memset(edge, 0, sizeof(edge));
        
        scanf("%d %d", &m, &k);
        for(i = 1; i <= k; i++){
            scanf("%d %d %d", &j, &x, &y);
            if(x==0 || y==0) continue;
            edge[x][y] = 1;
        }

        printf("%d\n", BipartiteMatching());
        
        scanf("%d", &n);
    }
}
