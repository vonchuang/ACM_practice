#include<cstdio>
#define MAX 3
#define LINE MAX*MAX
using namespace std;

int n;
int mat[LINE][LINE];
int col[LINE+1][LINE+1];
int row[LINE+1][LINE+1];
int block[LINE+1][LINE+1];
int end = 0;
void printMat(){
	int i,j;
	for(i=0;i<n*n;++i){
		for(j=0;j<n*n;++j){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	printf("===========================\n");
}

void backtrack(int dig, int x,int y){
	int i,j,k;

	if(dig == n*n*n*n){
		for(i=0;i<n*n;++i){
			printf("%d", mat[i][0]);
			for(j=1;j<n*n;++j){
				printf(" %d", mat[i][j]);
			}
			printf("\n");
		}
		end = 1;
		return;
	}

//	for(i=0;i<LINE;++i){
//		for(j=0;j<LINE;++j){
	if(y != (n*n-1)){
		i = x;
		j = y+1;
	}else{
		i = x+1;
		j = 0;
	}
			if(mat[x][y] == 0){
				int tmp = 0;
//				printf("(r%d c%d b%d)\n", x, y, n*((x)/3)+((y)/3));
				for(k=1;k<=n*n;++k){
//					printf("%d (r%d c%d b%d)\n", k, row[x][k], col[y][k], block[n*((x)/3)+((y)/3)][k]);

					if(row[x][k] == 0 && col[y][k] == 0 && block[n*((x)/n)+((y)/n)][k] == 0){
						row[x][k] = 1;
						col[y][k] = 1;
						block[n*((x)/n)+((y)/n)][k] = 1;
						mat[x][y] = k;
						tmp = 1;

//						printf("======================\n");
//						printf("(%d %d)%d\n",x,y,mat[x][y]);
//						printMat();

						backtrack(dig+1, i, j);
						if(end == 1)
							return;
//						printf("del %d(%d %d)\n",k, x, y);
						row[x][k] = 0;
						col[y][k] = 0;
						block[n*((x)/n)+((y)/n)][k] = 0;
						mat[x][y] = 0;
					}
				}

				//if(mat[i][j] == 0)	return;
			}else{
				int nx, ny;
				if(x != n*n-1){
					nx = i+1;
					ny = j;
				}else{
					nx = 0;
					ny = j+1;
				}

				backtrack(dig, i, j);	
			}
//		}
//	}
						return ;

}

int main(){
	int i, j, k;
	int cnt = 0;

		scanf("%d", &n);
		for(i=0;i<=n*n;++i){
			for(j=0;j<=n*n;++j){
				col[i][j] = 0;
				row[i][j] = 0;
				block[i][j] = 0;
			}
		}

		for(i=0;i<n*n;++i){
			for(j=0;j<n*n;++j){
				scanf("%d", &mat[i][j]);
				if(mat[i][j] != 0){
					row[i][mat[i][j]] = 1;
					col[j][mat[i][j]] = 1;
					block[n*((i)/n)+((j)/n)][mat[i][j]] = 1;
					cnt++;
				}
			}
		}
	
//		printf("cnt %d\n", cnt);
		backtrack(cnt, 0, 0);
		if(end == 0){
			printf("NO SOLUTION\n");
		}
		end = 0;
	while(scanf("%d", &n) != EOF){
		cnt = 0;

		printf("\n");
		// initialize
		for(i=0;i<=n*n;++i){
			for(j=0;j<=n*n;++j){
				col[i][j] = 0;
				row[i][j] = 0;
				block[i][j] = 0;
			}
		}

		// scan input
		for(i=0;i<n*n;++i){
			for(j=0;j<n*n;++j){
				scanf("%d", &mat[i][j]);
				if(mat[i][j] != 0){
					row[i][mat[i][j]] = 1;
					col[j][mat[i][j]] = 1;
					block[n*((i)/n)+((j)/n)][mat[i][j]] = 1;
					cnt++;
				}
			}
		}
	
//		printf("cnt %d\n", cnt);
		backtrack(cnt, 0, 0);
		if(end == 0){
			printf("NO SOLUTION\n");
		}
		end = 0;
	
	}
	return 0;
}
