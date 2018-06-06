#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define CONS 100
#define INF 99999999
#define MAX  505

using namespace std;

int N, m;
int vis[MAX], pa[MAX], neck[MAX];
int cap[MAX][MAX], flow[MAX][MAX];

bool DFS(int cur, int t, int n){
    int i, j, k;
    
    vis[cur] = 1;
    
    if(cur == t)    return true;
    for(i=0; i<=t; ++i){
        if(vis[i])    continue;
        if(neck[i] == 0 && (cap[cur][i] - flow[cur][i])>0){
            pa[i] = cur;
            neck[i] = min(neck[cur], cap[cur][i] - flow[cur][i]);
            if(DFS(i, t, n))    return true;
        }
    }
    return false;
    
    return 1;
}

void FindFlow(int n){
    int i;
    for (i = n; i != 0; i = pa[i]) {
        int pre = pa[i];
        flow[pre][i] += neck[n];
        flow[i][pre] -= neck[n];
    }
}
int FordFulkerson(int n) {
    n = n + CONS + 1;
    int res = 0;
    memset(flow, 0, sizeof(flow));
    while (1) {
        memset(pa, 0, sizeof(pa));
        memset(neck, 0, sizeof(neck));
        memset(vis, 0, sizeof(vis));
        neck[0] = INF;
        DFS(0, n, n);
        if (neck[n] == 0) break;
        res += neck[n];
        FindFlow(n);
        
    }
    return res;
}
int main() {
    while (scanf("%d", &N) != EOF) {
        
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        int num;
        for (int i = 1; i <= N; i++) {
            scanf("%d", &num);
            cap[i + CONS][i] = num;
        }
        scanf("%d", &m);
        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            cap[a][b + CONS] = c;
        }
        scanf("%d %d", &a, &b);
        for (int i = 0; i < a; i++) {
            scanf("%d", &c);
            cap[0][c + CONS] = INF;
        }
        for (int i = 0; i < b; i++) {
            scanf("%d", &c);
            cap[c][N + CONS + 1] = INF;
        }
        
        int res = FordFulkerson(N);
        printf("%d\n", res);
    }
    return 0;
}
