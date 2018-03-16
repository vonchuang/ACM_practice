#include<cstdio>
#include<queue>

#define MAX_SIZE 8
using namespace std;

int result = 0;
int level = 0;
int mat[MAX_SIZE][MAX_SIZE];
int vis[MAX_SIZE][MAX_SIZE];
int dir[8][2] = {{-1, 2}, {1, 2}, {-2, 1}, {2, 1},
				 {-1,-2}, {1,-2}, {-2,-1}, {2,-1}};

void BFS(int root_x ,int root_y){
	int end = 0;
	queue<int> que_x, que_y;
	que_x.push(root_x);
	que_y.push(root_y);
	vis[root_x][root_y] = 0;

	// start point = end point
	if(mat[root_x][root_y] == 2){
		result = 0;
		return;
	}	
	
	// BFS
	while(!que_x.empty()){
		int i;
		int check = 0;
		int cur_x = que_x.front();
		int cur_y = que_y.front();
		que_x.pop();
		que_y.pop();

		for(i=0; i<8; ++i){
			int nx = cur_x + dir[i][0];
			int ny = cur_y + dir[i][1];
			if((nx >= 0) && (ny >= 0) && (nx < MAX_SIZE) && (ny < MAX_SIZE)){

				if(mat[nx][ny] == 2){
					end = 1;
					result = vis[cur_x][cur_y] + 1;
					//printf("final:%d %d -> %d %d\n", cur_x, cur_y, nx, ny);
					break;
				}
			
				if(!vis[nx][ny]){
					vis[nx][ny] = vis[cur_x][cur_y] + 1;
					level = vis[nx][ny];
					que_x.push(nx);
					que_y.push(ny);
					//printf("push: %d %d-> %d %d(%d)\n",cur_x, cur_y, nx, ny, vis[nx][ny]);
				}
			}
		}
		//printf("level: %d\n\n", level);
		if(end == 1)
			break;
	}
	return;

}

int main(){
	int i, j;
	char colA, colB;
	int  rowA, rowB;
	char newline;

	for(i=0;i<MAX_SIZE; ++i){
		for(j=0; j<MAX_SIZE; ++j){
			vis[i][j] = 0;
			mat[i][j] = 0;
		}
	}

	while(scanf("%1c%1d %1c%1d", &colA, &rowA, &colB, &rowB) != EOF){

		// set matrix
		mat[colA - 'a'][rowA - 1] = 1;
		mat[colB - 'a'][rowB - 1] = 2;
		
		// BFS
		BFS(colA - 'a', rowA - 1);

		// print result
		printf("To get from %c%d to %c%d takes %d knight moves.\n", colA, rowA, colB, rowB, result);

		// initialize
		result = 0;
		level = 0;
		for(i=0;i<MAX_SIZE; ++i){
			for(j=0; j<MAX_SIZE; ++j){
				vis[i][j] = 0;
				mat[i][j] = 0;
			}
		}
		
		scanf("%c", &newline);

	}

	return 0;
}
