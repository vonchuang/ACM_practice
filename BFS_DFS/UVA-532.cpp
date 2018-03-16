#include<cstdio>
#include<queue>

#define MAX_SIZE 30
using namespace std;

int endcheck = 0, result = 0;
int L, R, C;
int sx, sy, sz;
int ex, ey, ez;
char mat[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int  vis[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int dir[6][3] = {            { 1, 0, 0},

				             {0,  0, 1},
				 { 0,-1, 0}            , {0, 1, 0},
    			             {0,  0,-1},

    			             {-1, 0, 0}};

void BFS(int root_x ,int root_y, int root_z){
    queue<int> que_x, que_y, que_z;
    que_x.push(root_x);
    que_y.push(root_y);
    que_z.push(root_z);
	
    vis[root_z][root_x][root_y] = 0;
    
    // BFS
    while(!que_x.empty()){
        int i;
        int check = 0;
        int cur_x = que_x.front();
        int cur_y = que_y.front();
        int cur_z = que_z.front();
        que_x.pop();
        que_y.pop();
        que_z.pop();
        
        for(i=0; i<6; ++i){
            int nx = cur_x + dir[i][1];
            int ny = cur_y + dir[i][2];
            int nz = cur_z + dir[i][0];
            if((nx >= 0) && (ny >= 0) && (nz >= 0) &&
			   (nx < MAX_SIZE) && (ny < MAX_SIZE) && (nz < MAX_SIZE)){
                
                if(mat[nz][nx][ny] == 'E'){
                    endcheck = 1;
                    result = vis[cur_z][cur_x][cur_y] + 1;
                    break;
                }
                
                if(!vis[nz][nx][ny] && mat[nz][nx][ny] == '.'){
                    vis[nz][nx][ny] = vis[cur_z][cur_x][cur_y] + 1;
                    //level = vis[nz][nx][ny];
					//printf("(%d, %d, %d) -> (%d, %d, %d)\n", cur_x, cur_y, cur_z, nx, ny, nz);
                    que_x.push(nx);
                    que_y.push(ny);
                    que_z.push(nz);
                }
            }
        }
        //printf("level: %d\n\n", level);
        if(endcheck == 1)
            break;
    }
    return;
    
}


int main(){
    int i, j, k;
	char newline;
    
    for(i=0;i<MAX_SIZE; ++i){
        for(j=0; j<MAX_SIZE; ++j){
			for(k=0; k<MAX_SIZE; ++k)
            	vis[i][j][k] = 0;
                mat[i][j][k] = '#';
        }
    }
    
    scanf("%d %d %d", &L, &R, &C);

	while(!(L == 0 && R == 0 && C == 0)){
        // scan input matrix
        for(i=0; i<L; ++i){
			scanf("%c", &newline);
            for(j=0; j<R; ++j){
				for(k=0; k<C; ++k){
                	scanf("%c", &mat[i][j][k]);
					// start point
					if(mat[i][j][k] == 'S'){
						sx = j;
						sy = k;
						sz = i;
					}
					// end point
					if(mat[i][j][k] == 'E'){
						ex = j;
						ey = k;
						ez = i;
					}
				}
				scanf("%c", &newline);
            }
        }
    	
        // BFS
		vis[sz][sx][sy] = 1;
        BFS(sx, sy, sz);
		
        // print result
       if(endcheck == 0)
		   printf("Trapped!\n");
	   else
		   printf("Escaped in %d minute(s).\n", result);

        // initialize
        endcheck = 0;
	    result = 0;
		for(i=0;i<L; ++i){
            for(j=0; j<R; ++j){
				for(k=0; k<C; ++k){
                	vis[i][j][k] = 0;
                	mat[i][j][k] = '#';
				}
            }
        }
        
    	scanf("%d %d %d", &L, &R, &C);
    }
    
    return 0;
}
