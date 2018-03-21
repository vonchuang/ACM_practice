#include<cstdio>

#define MAX 13
#define N 6
using namespace std;

int n;
int array[MAX] = {0};
int vis[MAX] = {0};
int ans[N] = {0};

void backtrack(int digit, int index){
	int i;
	
	if(digit == N){
		printf("%d", ans[0]);
		for(i=1; i<N; ++i){
			printf(" %d", ans[i]);
		}
		//if(!(ans[0] == array[n-N] && ans[N-1] == array[]))
		printf("\n");
		return;
	}

	for(i = index; i< n; ++i){
		if(vis[i] == 0){
//			printf("digit:%d, i:%d\n", digit, i);
			vis[i] = 1;
			ans[digit] = array[i];
			backtrack(digit+1, i);
			vis[i] = 0;
		}
	}	

	//vis[index] = 0;
	//return;


}

int main(){


	int i, j;

	scanf("%d", &n);

	while(n != 0){
		// scan input
		for(i=0; i<n; ++i)
			scanf("%d", &array[i]);

		// backtracking
		/*	
		for(i=0; i<(n-N+1); ++i){
			backtrack(0, i);
			for(j=0; j<n; ++j){
				vis[j] = 0;
			}
		}
		*/

		backtrack(0, 0);
		// initiMaalize
		for(i=0;i<n;++i){
			array[i] = 0;
			vis[i] = 0;
		}
		scanf("%d", &n);
		if(n != 0)
			printf("\n");
		
	}
	

	return 0;
}
