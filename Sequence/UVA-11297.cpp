#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 999999999
#define MAX 505

using namespace std;
 
int matrixMax[MAX * 4][MAX * 4];
int matrixMin[MAX * 4][MAX * 4];
 
bool check;

int LC(int i) { return i << 1; }
int RC(int i) { return i << 1 | 1; }

void BuildY(int ix,int iy,int L,int R)
{
    if(L == R){
        if(check){
            scanf("%d", &matrixMin[ix][iy]);
            matrixMax[ix][iy] = matrixMin[ix][iy];
        }else{
            matrixMax[ix][iy] = max(matrixMax[LC(ix)][iy],matrixMax[RC(ix)][iy]);
            matrixMin[ix][iy] = min(matrixMin[LC(ix)][iy],matrixMin[RC(ix)][iy]);
        }
        return ;
    }

    int M = (L + R) / 2;
    BuildY(ix, LC(iy), L, M);
    BuildY(ix, RC(iy), M + 1, R);
    
    matrixMax[ix][iy] = max(matrixMax[ix][LC(iy)], matrixMax[ix][RC(iy)]);
    matrixMin[ix][iy] = min(matrixMin[ix][LC(iy)], matrixMin[ix][RC(iy)]);
    
}
 
void BuildX(int iy,int L,int R,int m)
{
    if(L == R){
        check = true;
        BuildY( iy, 1, 1, m);
        return ;
    }
    
    int M = (L + R) / 2;
    BuildX( LC(iy), L    , M, m);
    BuildX( RC(iy), M + 1, R, m);
    check = false;
    BuildY( iy, 1, 1, m);

}

void UpdateY(int ix, int iy, int L, int R, int p, int v)
{
    if(L == R){
        if(check)
            matrixMax[ix][iy] = matrixMin[ix][iy] = v;
        else{
            matrixMax[ix][iy] = max(matrixMax[LC(ix)][iy], matrixMax[RC(ix)][iy]);
            matrixMin[ix][iy] = min(matrixMin[LC(ix)][iy], matrixMin[RC(ix)][iy]);
        }
        return ;
    }
    
    int M = (L + R) / 2;
    if(p <= M)
        UpdateY( ix, LC(iy), L, M, p, v);
    else
        UpdateY( ix, RC(iy), M + 1, R, p, v);
    
    matrixMax[ix][iy] = max(matrixMax[ix][LC(iy)], matrixMax[ix][RC(iy)]);
    matrixMin[ix][iy] = min(matrixMin[ix][LC(iy)], matrixMin[ix][RC(iy)]);

}
 
void UpdateX(int iy, int L, int R, int x, int y, int v, int n)
{
    if(L == R){
        check = true;
        UpdateY( iy, 1, 1, n, y, v);
        return ;
    }
    
    int M = (L + R) / 2;
    if(x <= M)
        UpdateX( LC(iy), L, M, x, y, v, n);
    else
        UpdateX( RC(iy), M + 1, R, x, y, v, n);
    check = false;
    UpdateY( iy, 1, 1, n, y, v);

}

void QueryY(int ix, int iy, int L, int R, int rL, int rR, int &Max, int &Min)
{
    if(rL <= L && R <= rR){
        Max = max(Max, matrixMax[ix][iy]);
        Min = min(Min, matrixMin[ix][iy]);
        return ;
    }
    
    int M = (L + R) / 2;
    if(rL <= M)
        QueryY(ix, LC(iy), L    , M, rL, rR, Max, Min);
    if(rR > M)
        QueryY(ix, RC(iy), M + 1, R, rL, rR, Max, Min);

}

void QueryX(int iy, int L, int R, int rL, int rR, int rL2, int rR2, int &Max, int &Min,int n)
{
    if(rL <= L && R <= rR){
        QueryY( iy, 1, 1, n, rL2, rR2, Max, Min);
        return ;
    }
    
    int M = (L + R) / 2;
    if(rL <= M)
        QueryX( LC(iy), L    , M, rL, rR, rL2, rR2, Max, Min, n);
    if(rR >  M)
        QueryX( RC(iy), M + 1, R, rL, rR, rL2, rR2, Max, Min, n);

}
 
int main()
{
    int n, q, x1, x2, y1, y2, v, i;
    char op;
    while(scanf("%d", &n) != EOF)
    {
        BuildX( 1, 1, n, n);
        scanf("%d", &q);
        for(i=0; i<q; ++i)
        {
            scanf("%c", &op);   // for '\n'
            scanf("%c", &op);
            if(op == 'c'){
                scanf("%d%d%d", &x1, &y1, &v);
                UpdateX( 1, 1, n, x1, y1, v, n);
            }else if(op == 'q'){
                int Max = -INF, Min = INF;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                QueryX( 1, 1, n, x1, x2, y1, y2, Max, Min, n);
                printf("%d %d\n", Max, Min);
            }
        }
    }
    return 0;
}
