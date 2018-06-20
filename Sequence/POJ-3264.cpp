#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 50005
#define INF 9999999
int Max,Min;

struct Node{
    int L,R;
    int Max,Min;
}node[MAX*3];

int LC(int i) { return i*2; }
int RC(int i) { return i*2+1; }

void Build(int L,int R, int i)
{
    if(L == R){
        scanf("%d", &node[i].Max);
        node[i].Min = node[i].Max;
        node[i].L = L;
        node[i].R = R;
        return ;
    }

    node[i].L = L;
    node[i].R = R;

    int M = (L + R) / 2;
    Build(L  , M, LC(i));
    Build(M+1, R, RC(i));

    node[i].Max = max(node[LC(i)].Max, node[RC(i)].Max);
    node[i].Min = min(node[LC(i)].Min, node[RC(i)].Min);
}

void Query(int L,int R, int i)
{
    if(node[i].Max < Max && node[i].Min > Min)
        return ;
    
    if(node[i].L==L && node[i].R==R){
        Max = max(Max, node[i].Max);
        Min = min(Min, node[i].Min);
        return ;
    }

    int M = (node[i].L + node[i].R) / 2;
    if(M >= R){
        Query(L, R, LC(i));
    }
    else if(M < L){
        Query(L, R, RC(i));
    }
    else{
        Query(L,   M, LC(i));
        Query(M+1, R, RC(i));
    }
}

int main()
{
    int N, Q, A, B, i;
    
    while(scanf("%d%d",&N, &Q) != EOF){
        Build(1, N, 1);
        for(i=0; i<Q; ++i){
            scanf("%d%d",&A, &B);
            Max = -INF;
            Min = INF;
            Query(A, B, 1);
            printf("%d\n",Max - Min);
        }
    }
    return 0;
}
