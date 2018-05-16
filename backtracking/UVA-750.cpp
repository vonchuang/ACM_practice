#include<cstdio>

#define MAX 8

int k, result;
int diag1, diag2;
int board[MAX][MAX];
int visCol[MAX];
int visRow[MAX];
int ans[MAX];

using namespace std;

void backtrack(int digit, int index){
	int i;
	
	if(digit == MAX){
		int tmp = 0;
		for(i=1; i<MAX; ++i){
			tmp += ans[i];
		}
		if(tmp > result){
			result = tmp;
		}
		return;
	}

	for(i = index; i< n; ++i){
		if((visCol[i] == 0) && (visRow[i] == 0)){
			visCol[i] = 1;
			ans[digit] = array[i];
			backtrack(digit+1, i);
			vis[i] = 0;
		}
	}	

}

int main(){

	int i, j, x, y;
	while(scanf("%d", &k) != EOF){
		for(i=0;i<k;++i){
			scanf("%d %d", &x, &y);

		}

		for(i=0; i<MAX; ++i){
			for(j=0; j<MAX; ++j){
				scanf("%d", &board[i][j]);
			}
		}
	
	
	}

	return 0;
}
