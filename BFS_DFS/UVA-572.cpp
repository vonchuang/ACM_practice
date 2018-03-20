#include<cstdio>

#define MAX_SIZE 100
using namespace std;

int n, m;
int count = 0;
char mat[MAX_SIZE][MAX_SIZE];
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
        
        if((nx >= 0 && ny >= 0) && (nx < m && ny < n) &&
           (vis[nx][ny] == 0) && (mat[nx][ny] == '@')){
            DFS(nx, ny);
        }
    }
}

int main(){
    int i, j;
	char line;
    
    for(i=0;i<MAX_SIZE; ++i){
        for(j=0; j<MAX_SIZE; ++j){
            vis[i][j] = 0;
        }
    }
    
	scanf("%d %d", &m, &n);

    while(!(m==0 && n==0)){
        // scan input matrix
        for(i=0; i<m; ++i){
		scanf("%c", &line);
            for(j=0; j<n; ++j){
                scanf("%c", &mat[i][j]);
            }
        }
		scanf("%c", &line);
        


        // DFS
        for(i = 0; i<m; ++i)
            for(j=0; j<n; ++j)
                if((vis[i][j] == 0) && (mat[i][j] == '@')){
                    count++;
                    //printf("(%d %d)count %d\n",i, j, count);
                    DFS(i ,j);
                }
        
        // print result
        printf("%d\n", count);
        
        // initialize
        for(i=0;i<m; ++i){
            for(j=0; j<n; ++j){
                vis[i][j] = 0;
                mat[i][j] = '*';
            }
        }
        
        count = 0;
        
		scanf("%d %d", &m, &n);
    }
    
    return 0;
}
