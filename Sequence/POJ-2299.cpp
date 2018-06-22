#include <cstdio>
#include <cstring>

#define MAX 1001000  

using namespace std;

int tree[MAX];

int LowBit(int n){
    return n & -n;
}  
  
void Update(int i){
    while(i < MAX){
        tree[i] += 1 ;
        i += LowBit(i);
    }  
}  
  
long long int Sum(int x){
    long long int sum = 0 ;
    while(x > 0){
        sum += tree[x] ;
        x -= LowBit(x) ;
    }  
    return sum ;
}  
  
int main(){
    int n, i, x, cnt;
    scanf("%d", &n);
    while(n != 0){
        long long int sum = 0;
        memset(tree, 0, sizeof(tree));
        
        for(i = 0 ; i < n ; ++i){
            scanf("%d", &x);
            x++;
            cnt = Sum(x);
            sum += i - cnt ;
            Update(x) ;
        }
        
        printf("%lld\n", sum) ;
        scanf("%d", &n);
    }  
    return 0 ;  
}  
