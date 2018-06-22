#include<cstring>
#include<cstdio>  

#define MAX 32005

using namespace std;  

int n;  
int cnt[MAX], tree[MAX];
  
int LowBit(int x){
    return x & (-x);  
}  
  
void Updata(int i, int delta){
    while(i < MAX){
        tree[i] += delta;
        i += LowBit(i);
    }  
}  
  
int Sum(int x){
    int sum = 0;
    while(x > 0){
        sum += tree[x];
        x -= LowBit(x);
    }  
    return sum;
}  
  
int main(){
    int x, y, i;
    while(scanf("%d", &n) != EOF){
        memset(cnt, 0, sizeof(cnt));
        memset(tree, 0, sizeof(tree));
        
        for(i = 0; i < n; ++i){
            scanf("%d%d", &x, &y);  
            x++;
            cnt[Sum(x)]++;
            Updata(x, 1);
        }
        
        for(i = 0; i < n; ++i)
            printf("%d\n", cnt[i]);
    }  
    return 0;  
}  
