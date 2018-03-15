#include<cstdio>

#define MAX_SIZE 200
using namespace std;

int n;
int time = 1;
int check_row = 0, check_col = 0;
char mat[MAX_SIZE][MAX_SIZE];
int  vis[MAX_SIZE][MAX_SIZE];
int col[MAX_SIZE] = {0}, row[MAX_SIZE] = {0};
int dir[6][2] = {         {0,  1}, {1, 1},
				 {-1, 0}         , {1, 0},
				 {-1,-1}, {0, -1}        };

void DFS(int cur_x, int cur_y){
	if(vis[cur_x][cur_y] == 0 && (check_row != 1 && check_col != 1)){
		int i, j;
		vis[cur_x][cur_y] = 1;
		//printf("(%d,%d)\n", cur_x, cur_y);
		if(mat[cur_x][cur_y] == 'b'){
			check_row = 1;
			row[cur_x] = 1;
		
			for(i=0; i<n; ++i){
				if(row[i] == 0){
					check_row = 0;
					break;
				}
			}
			if(check_row == 1){
				return;
			}
		}else if(mat[cur_x][cur_y] == 'w'){
			check_col = 1;
			col[cur_y] = 1;
		
			for(i=0; i<n; ++i){
				if(col[i] == 0){
					check_col = 0;
					break;
				}
			}
			if(check_col == 1){
				return;
			}
		}

		for(i=0; i<6; ++i){
			int nx = cur_x + dir[i][0];
			int ny = cur_y + dir[i][1];

			if((nx >= 0 && ny >= 0) &&
					(nx < n && ny < n) &&
					(vis[nx][ny] == 0) &&
					(mat[nx][ny] == mat[cur_x][cur_y])){
					check_row = 0;
					check_col = 0;
					DFS(nx, ny);
			
					if(check_row == 1 || check_col == 1)
						return;
			}
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

	scanf("%d", &n);

	while(n != 0){
		// scan input matrix
		char newline;
		scanf("%c", &newline);
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				scanf("%c", &mat[i][j]);
			}
			scanf("%c", &newline);
		}

		// DFS
		check_row = 0;
		check_col = 0;
		for(i = 0; i<n; ++i)
			for(j=0; j<n; ++j)
				DFS(i ,j);

		// print result
		printf("%d ", time);
		if(check_row == 1)
			printf("B\n");
		else if(check_col == 1)
			printf("W\n");


		// initialize
		for(i=0;i<n; ++i){
			for(j=0; j<n; ++j){
				vis[i][j] = 0;
				mat[i][j] = 0;
			}
			col[i] = 0;
			row[i] = 0;
		}
		time++;
		scanf("%d", &n);

	}

	return 0;
}
