#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 999999999
#define MAX 205

using namespace std;

struct Edge{
    int u, v, len;
}E[40001];

int N, P, T;
int cap[MAX][MAX], flow[MAX][MAX];
int neck[MAX], pa[MAX], vis[MAX];


bool DFS(int cur, int t, int n){
    int i, j, k;
    
    vis[cur] = 1;
    
    if(cur == t)    return true;
    for(i=1; i<=n; ++i){
        if(vis[i])    continue;
        if(neck[i] == 0 && (cap[cur][i] - flow[cur][i])>0){
            pa[i] = cur;
            neck[i] = min(neck[cur], cap[cur][i] - flow[cur][i]);
            if(DFS(i, t, n))    return true;
        }
    }
    return false;
    
}

void FindFlow(){
    int i;
    
    for(i=N; i!=1; i=pa[i]){
        int pre = pa[i];
        flow[pre][i] += neck[N];
        flow[i][pre] -= neck[N];
    }
}

int FordFulkerson(int len)
{
    int i;
    int ret = 0;
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    
    for (i = 0; i < P; ++i) {
        if (E[i].len <= len){
            cap[E[i].v][E[i].u]++;
            cap[E[i].u][E[i].v] = cap[E[i].v][E[i].u];
        }
    }

    while (1) {
        memset(neck, 0, sizeof(neck));
        memset(vis, 0, sizeof(vis));
        neck[1] = INF;
        DFS(1, N, N);
        
        if (neck[N] == 0) break;
        FindFlow();

        ret += neck[N];
    }
    return ret;
}


int main()
{
    int i;
    int maxLen = 0;
    int left, right, mid;
    scanf("%d %d %d", &N, &P, &T);
    
    for (i = 0; i < P; ++i) {
        scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].len);
        maxLen = max(maxLen, E[i].len);
    }
    
    left = 0;
    right = maxLen;
    while (left != right) {
        mid = (left + right) / 2;
        
        if (FordFulkerson(mid) >= T) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
}
