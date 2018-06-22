#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 1050

using namespace std;

int t[MAX][MAX];
int S;

int LowBit(int n){
    return n & -n;
}

void Updata(int x, int y, int delta)
{  
    int i,j;
    for(i=x; i<=S; i+=LowBit(i))
        for(j=y; j<=S; j+=LowBit(j))
            t[i][j] += delta;
}

int Sum(int x, int y)
{  
    int sum = 0;
    
    while(x > 0){
        int tmp = y;
        while(tmp > 0){
            sum += t[x][tmp];
            tmp -= LowBit(tmp);
        }
        x -= LowBit(x);
    }
    return sum;  
}

int main()  
{  
    int in0, instr, x, y, A;
    int x1, y1, x2, y2;
    while(scanf("%d%d", &in0, &S) != EOF){
        S++;
        
        memset(t, 0, sizeof(t));
        
        scanf("%d",&instr);
        
        while( instr != 3 )
        {
            if( instr == 1 )
            {
                scanf("%d%d%d",&x,&y,&A);
                x++;
                y++;
                Updata(x, y, A);
            }
            if( instr == 2 )
            {
                int ans;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                x1++;
                y1++;
                x2++;
                y2++;
                ans = Sum(x2,y2) - Sum(x1-1,y2) - Sum(x2,y1-1) + Sum(x1-1,y1-1);
                printf("%d\n", ans);
            }
            
            scanf("%d", &instr);
        }
    }
return 0;  
}  
