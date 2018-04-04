#include<cstdio>
#include<vector>
#define MAX 17

using namespace std;

int vis[MAX] = {0};
int prime_check[100] = {0};
int ans[MAX] = {0};
int n;
int cnt = 1;
vector<int> prime;

void backtrack(int dig, int x){
	int i;
	
//	printf("dig %d, n %d, x %d\n",dig,n,x);
	if(dig == n){
		if(prime_check[1+ans[n-1]]){
			printf("%d", ans[0]);
			for(i=1;i<n;++i){
				printf(" %d", ans[i]);
			}
			printf("\n");
			return;
		}
	}

	for(i=1; i<=n; ++i){
		if(vis[i] == 0 && prime_check[i+x]){
			//if((i != n) || (i == n && prime_check[1+i])){
				vis[i] = 1;
				ans[dig] = i;
				backtrack(dig+1, i);
				vis[i] = 0;
			//}
		}
	}

	return ;
}

bool is_prime(int x){
	int i;
	for(i=0;prime[i]*prime[i] <=x;++i){
		if(x%prime[i] == 0)
			return false;
	}
	return true;
}

void make_prime(){
	int i,gap;
	prime.push_back(2);
	prime.push_back(3);
	prime_check[2] = 1;
	prime_check[3] = 1;
	for(i=5,gap=2;i<=100;i+=gap,gap=6-gap){
		if(is_prime(i)){
			prime.push_back(i);
			prime_check[i] = 1;
			//printf("%d ",i);
		}
	}

}

int main(){
	int i, j;
	make_prime();

		scanf("%d", &n);
		printf("Case %d:\n", cnt++);
		ans[0] = 1;
		vis[1] = 1;
		backtrack(1,1);
	
		for(i=1;i<=n;++i){
			vis[i] = 0;
		}
	while(scanf("%d", &n) != EOF){

		printf("\n");	
		printf("Case %d:\n", cnt++);
		ans[0] = 1;
		vis[1] = 1;
		backtrack(1,1);
	
		for(i=1;i<=n;++i){
			vis[i] = 0;
		}
	}

	
	

	return 0;
}
