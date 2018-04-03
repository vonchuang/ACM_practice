#include<cstdio>

#define MAX 6
#define LINE 9

using namespace std;

int mat[MAX][MAX];
int vis[MAX][MAX];
int ans[LINE];

void backtrack(int dig, int n){
	int i;

	if(dig == LINE){
		for(i=0;i<LINE;++i){
			printf("%d", ans[i]);
		}
		printf("\n");
		return;
	}

	for(i=1; i<=MAX; ++i){
		if(vis[n][i] == 0 && mat[n][i] == 1){
			vis[n][i] = 1;
			vis[i][n] = 1;
			ans[dig] = i;
			backtrack(dig+1, i);
			vis[n][i] = 0;
			vis[i][n] = 0;
		}
	}

	return ;
}

int main(){

	mat[1][2] = 1;
	mat[1][3] = 1;
	mat[1][5] = 1;
	
	mat[2][1] = 1;
	mat[2][3] = 1;
	mat[2][5] = 1;

	mat[3][1] = 1;
	mat[3][2] = 1;
	mat[3][4] = 1;
	mat[3][5] = 1;

	mat[4][3] = 1;
	mat[4][5] = 1;

	mat[5][1] = 1;
	mat[5][2] = 1;
	mat[5][3] = 1;
	mat[5][4] = 1;

	ans[0] = 1;
	backtrack(1,1);

	return 0;
}
