#include<cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 9

using namespace std;

int n;
int result = 0;
int mat[MAX][MAX];
int vis[MAX][MAX];

/*
void printMat(){
	int i,j;
	printf("=================================\n");
	for(i=0;i<MAX;++i){
		for(j=0;j<MAX;++j){
			if(vis[i][j] != 0)
				printf("%2d ", mat[i][j]);
			else
				printf("   ");
		}
		printf("\n");
	}

	printf("======================================\n");
}
*/
int check(int x, int a){
    int i, j;
    // check row and col
    for(i=1;i<x;++i){
        // row
        if(vis[i][a] != 0){
            return 0;
        }
	}
	for(i=1;i<a;++i){
        //col
        if(vis[x][i] != 0){
            return 0;
        }
        
    }
    
    // check diag
	for(i=1;i<MAX;++i){
		for(j=0;j<MAX;++j){
			int tx = ((i-x)>0)? (i-x): (x-i);
			int ty = ((j-a)>0)? (j-a): (a-j);
			if(tx == ty && vis[i][j]){
				return 0;
			}
			
		}
	}
	
	/*
    if(a == x){
        for(i=0;i<MAX;++i){
            if(vis[i][i] != 0){
                return 0;
            }
        }
    }
    
    if(a == (9-x)){
        for(i=0;i<MAX;++i){
            if(vis[i][9-i] != 0){
                return 0;
            }
        }
    }
    */
	return 1;
}


void backtrack(int dig, int x, int y, int sum){
	int i,j,k,a,b;

	// ans
	if(dig > MAX-1){
		if(sum > result)
			result = sum;
		return;
	}
	
	for(a=1;a<MAX;++a){		
		
		if(check(x, a) && vis[x][a] == 0){
			vis[x][a] = 1;
			backtrack(dig+1, x+1 ,a, sum+mat[x][a]);
			vis[x][a] = 0;
		}
		
	}

	return ;

}

int main(){
	int i, j, k;

	scanf("%d", &n);
	while(n--){

		result = 0;
		// initialize
		for(i=0;i<MAX;++i){
			for(j=0;j<MAX;++j){
				mat[i][j] = 0;
				vis[i][j] = 0;
			}
		}

		// scan input
		for(i=1;i<MAX;++i){
			for(j=1;j<MAX;++j){
				scanf("%d", &mat[i][j]);
			}
		}

		backtrack(1, 1, 0, 0);
        //dfs(1, 0);
		printf("%5d\n", result);
	}
	return 0;
}
