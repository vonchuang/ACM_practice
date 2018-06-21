#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100005

using namespace std;

int node[MAX *4], path[MAX], shift[MAX];
int cnt = 0;

int LC(int i) { return i*2; }
int RC(int i) { return i*2+1; }

int Build(int L, int R, int i){
    
    if (L == R){
         scanf("%d", node + (path[++cnt] = i));
        return node[i];
    }
    
    int M =(L + R) / 2, cL, cR;
    cL = Build(L, M, LC(i)); cR = Build(M + 1, R, RC(i));
    node[i] = min(cL, cR);
    
    return node[i];
}

int Query(int L, int R, int i, int rL, int rR){
    if (R <= rR && L >= rL)
        return node[i];
    
    int M = (L + R) / 2, cL, cR;
    if (rR <= M)
        return Query(L, M, LC(i), rL, rR);
    else if (M < rL)
        return Query(M + 1, R, RC(i), rL, rR);
    else{
        cL = Query(L, M, LC(i), rL, M); cR = Query(M + 1, R, RC(i), M + 1, rR);
        return min(cL, cR);
    }
}

void Updata(int i, int n){
    int tmp;
    
    while (i /= 2){
        
        tmp = min(node[LC(i)], node[RC(i)]);
        
        if (tmp == node[i])
            return;
        
        node[i] = tmp;
    }
}
int main(){
    memset(node, 127, sizeof(node));
    int N, Q, i, j, k, tmp, A, B;
    char ch[20], c;
    
    scanf("%d%d", &N, &Q);
    
    Build(1, N, 1);
    scanf("%c", &c);
    for(k=0; k<Q; ++k){
        scanf("%c%c%c%c%c%c", &ch[0], &ch[1], &ch[2], &ch[3], &ch[4], &ch[5]);
        
        if (ch[0] == 'q'){
            scanf("%d,%d)", &A, &B);
            
            printf("%d\n", Query(1, N, 1, A, B));
        }
        else{
            j = 0;
            while(c != ')'){
                scanf("%d", &shift[j++]);
                scanf("%c", &c);
            }
            tmp = node[path[shift[0]]];
            for (i=0; i < j - 1; ++i){
                node[path[shift[i]]] = node[path[shift[i + 1]]];
                Updata(path[shift[i]], N);
            }
            node[path[shift[i]]] = tmp;
            Updata(path[shift[i]], N);
        }
        scanf("%c", &c);
    }
    
    return 0;
}
