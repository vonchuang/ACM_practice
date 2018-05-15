#include <cstdio>
#include <cmath>
#include <algorithm>

#define MAX 305
#define INF 9999

using namespace std;

int N, M, S;
int dp[MAX][MAX];


int main (){
	int i, j, k;
	scanf("%d", &N);

	while(N--){
		int result = INF;
		scanf("%d%d", &M, &S);
		
		// initialize
		for(i=0; i<=S; ++i){
			for(j=0; j<=S; ++j){
				dp[i][j] = INF;
			}
		}
		dp[0][0] = 0;

		// calc
		for(i=0; i<M; ++i){
			int x, y;
			scanf("%d%d", &x, &y);
			for(j=x; j<=S; ++j){
				for(k=y; k<=S; ++k){
					dp[j][k] = min(dp[j][k], dp[j-x][k-y]+1);
				}
			}
		}

		for(i=0; i<=S; ++i){
			for(j=0; j<=S; ++j){
//				printf("%d ", dp[i][j]);
				if(abs(S - sqrt(i*i + j*j)) < 0.001 ){
					result = min(result, dp[i][j]);
				}
			}
//			printf("\n");
		}

		if(result == INF)
			printf("not possible\n");
		else
			printf("%d\n", result);

	}


	return 0;
}
