#include <cstdio>
#include <cstring>
#include <cmath>

#define MAX 205

using namespace std;

struct Point{
    int x, y;
};

int t, n, m;
int edge[MAX][MAX], gt[MAX];
int llink[MAX], rlink[MAX], used[MAX];

int dfs(int now) {
    int next, x;
    for(next = 0; next < gt[now]; next++) {
        x = edge[now][next];
        if(!used[x]) {
            used[x] = 1;
            if(rlink[x] == 0 || dfs(rlink[x])) {
                llink[now] = x;
                rlink[x] = now;
                return 1;
            }
        }
    }
    return 0;
}


int BipartiteMatching(){
    int ans = 0,i;
    
    // Numbering from 1 to nL/nR
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));
    
    // Try all vertices ont the left side
    for(i = 1; i <= n; i++) {
        if(!llink[i]) {
            memset(used, 0, sizeof(used));
            if(dfs(i))
                ans++;
        }
    }
    
    return ans;
}

float dist(int x1, int y1, int x2, int y2){
    int disx = x1 - x2;
    int disy = y1 - y2;
    return sqrt(disx*disx + disy*disy);
}

int main() {
    int i, j, k;
    
    scanf("%d", &t);
    while(t--) {
        Point route[MAX], place[MAX];
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; i++)
            scanf("%d %d", &route[i].x, &route[i].y);
        for(i = 1; i <= m; i++)
            scanf("%d %d", &place[i].x, &place[i].y);
        memset(gt, 0, sizeof(gt));
        for(i = 1; i < n; i++) {
            float len = 2*dist(route[i].x, route[i].y, route[i+1].x, route[i+1].y);
            
            for(j = 1; j <= m; j++) {
                float len1 = dist(route[i].x, route[i].y, place[j].x, place[j].y);
                float len2 = dist(route[i+1].x, route[i+1].y, place[j].x, place[j].y);
                
                if(len1+len2 <= len)
                    edge[i][gt[i]++] = j;
            }
        }

        printf("%d\n", BipartiteMatching()+n);
        
        for(i = 1; i <= n; i++) {
            if(i != 1)  printf(" ");
            printf("%d %d", route[i].x, route[i].y);
            if(llink[i])
                printf(" %d %d", place[llink[i]].x, place[llink[i]].y);
        }
        printf("\n");
        if(t)
            printf("\n");
    }
}
