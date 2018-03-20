#include<cstdio>
//#include<queue>
#include<algorithm>
#include<ctime>

#define MAX_SIZE 50
using namespace std;

int n, m;
int timecnt = 1;
int countNum = 0;
int indexcnt = 0;
char mat[MAX_SIZE][MAX_SIZE];
//int vis[MAX_SIZE][MAX_SIZE];
//char alph[MAX_SIZE] = {'Z'};
//int size[MAX_SIZE] = {0};

struct holeStruct{
	char alph;
	int size;
}hole[MAX_SIZE*MAX_SIZE];

int dir[4][2] = {		{0,  1},
    			 {-1, 0}         , {1, 0},
    			 		{0, -1}};
/*
void BFS(int root_x ,int root_y){
    queue<int> que_x, que_y;
    que_x.push(root_x);
    que_y.push(root_y);
    vis[root_x][root_y] = 0;
    
    // BFS
    while(!que_x.empty()){
        int i;
        int check = 0;
        int cur_x = que_x.front();
        int cur_y = que_y.front();
        que_x.pop();
        que_y.pop();
        
        for(i=0; i<4; ++i){
            int nx = cur_x + dir[i][0];
            int ny = cur_y + dir[i][1];
            if((nx >= 0) && (ny >= 0) && (nx < n) && (ny < m)){
                
                if(!vis[nx][ny] && (mat[cur_x][cur_y] == mat[nx][ny])){
                    vis[nx][ny] = 1;
                    que_x.push(nx);
                    que_y.push(ny);
					countNum++;
                    //printf("push: %d %d-> %d %d(%d)\n",cur_x, cur_y, nx, ny, vis[nx][ny]);
                }
            }
        }
    }
    return;
    
}
*/


void DFS(int cur_x, int cur_y){
    int i, j;
	char tmp = mat[cur_x][cur_y];
	mat[cur_x][cur_y] = '.';
    //vis[cur_x][cur_y] = 1;
    
    for(i=0; i<4; ++i){
        int nx = cur_x + dir[i][0];
        int ny = cur_y + dir[i][1];
        
        if((nx >= 0 && ny >= 0) && (nx < m && ny < n) &&
           (mat[nx][ny] != '.') && (mat[nx][ny] == tmp)){
           //(vis[nx][ny] == 0) && (mat[nx][ny] >='A' && mat[nx][ny]<='Z') && (mat[nx][ny] == mat[cur_x][cur_y])){
            countNum++;
			DFS(nx, ny);
        }
    }
}

bool cmp(holeStruct a, holeStruct b){
	return (a.size == b.size)?(a.alph < b.alph): (a.size > b.size);
}

int main(){
    int i, j, k, x;
	char line;
    clock_t begin, end;

	begin = clock();
/*
    for(i=0;i<MAX_SIZE; ++i){
        for(j=0; j<MAX_SIZE; ++j){
            vis[i][j] = 0;

        }
    }
  */  
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
        for(i = 0; i<m; ++i){
            for(j=0; j<n; ++j){
                if(mat[i][j] != '.'){
                //if((vis[i][j] == 0) && (mat[i][j] >='A' && mat[i][j] <='Z')){
                    countNum++;
					hole[indexcnt].alph = mat[i][j];
                    DFS(i ,j);
					//BFS(i, j);
                    hole[indexcnt].size = countNum;
					indexcnt++;
					// sort result
					/*
					for(k=0; k<index; k++){
						if((count == size[k]) && (mat[i][j] <= alph[k])){
							for(x=index; x>k; --x){
								size[x] = size[x-1];
								alph[x] = alph[x-1];
							}
							size[k] = count;
							alph[k] = mat[i][j];
							break;
						}else if(count > size[k]){
							for(x=index; x>k; --x){
								size[x] = size[x-1];
								alph[x] = alph[x-1];
							}
							size[k] = count;
							alph[k] = mat[i][j];
							break;
						}
					}
					*/

					countNum = 0;
				}
			}
        }

		//sort
        sort(hole, hole+indexcnt, cmp);
        
        // print result
        printf("Problem %d:\n", timecnt);
		for(i=0; i<indexcnt; ++i){
			printf("%c %d\n", hole[i].alph, hole[i].size);
		}
        
        // initialize
        for(i=0;i<m; ++i){
            for(j=0; j<n; ++j){
//                vis[i][j] = 0;
                mat[i][j] = '.';
            }
        }

		for(i=0; i<indexcnt; ++i){
			hole[i].alph = 'Z';
			hole[i].size = 0;
		}
        timecnt++;
        countNum = 0;
		indexcnt = 0;
        
		scanf("%d %d", &m, &n);
    }

	end = clock();
	double spend = (double)(end-begin) / CLOCKS_PER_SEC;

	//printf("time: %lf\n", spend);
    
    return 0;
}

