#include<cstdio>

#define MAX_SIZE 25
using namespace std;

int n;
int time = 1;
int count = 0;
int mat[MAX_SIZE][MAX_SIZE];
int vis[MAX_SIZE][MAX_SIZE];
int dir[8][2] = {{-1, 1}, {0,  1}, {1, 1},
				 {-1, 0}         , {1, 0},
				 {-1,-1}, {0, -1}, {1,-1}};

void DFS(int cur_x, int cur_y){
	int i, j;
	vis[cur_x][cur_y] = 1;

	for(i=0; i<8; ++i){
		int nx = cur_x + dir[i][0];
		int ny = cur_y + dir[i][1];

		if((nx >= 0 && ny >= 0) && (nx < n && ny < n) &&
				(vis[nx][ny] == 0) && (mat[nx][ny] == 1)){
				DFS(nx, ny);		
		}
	}
}

int main(){
	int i, j;

	for(i=0;i<MAX_SIZE; ++i){
		for(j=0; j<MAX_SIZE; ++j){
			vis[i][j] = 0;
		}
	}

	while(scanf("%d", &n) != EOF){
		// scan input matrix
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				scanf("%1d", &mat[i][j]);
			}
		}

		// DFS
		for(i = 0; i<n; ++i)
			for(j=0; j<n; ++j)
				if((vis[i][j] == 0) && (mat[i][j] == 1)){
					count++;
					//printf("(%d %d)count %d\n",i, j, count);
					DFS(i ,j);
				}

		// print result
		printf("Image number %d contains %d war eagles.\n", time, count);

		// initialize
		for(i=0;i<n; ++i){
			for(j=0; j<n; ++j){
				vis[i][j] = 0;
				mat[i][j] = 0;
			}
		}
		time++;
		count = 0;

	}

	return 0;
}
