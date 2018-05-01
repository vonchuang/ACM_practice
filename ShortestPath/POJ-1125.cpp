#include<cstdio>

#define MAX 105
#define TMAX 205
#define INF 999
using namespace std;

int dis[MAX][MAX];
int len[MAX][MAX];
int contact[TMAX][2];
int count = 0;
int N;

void Floyd(){
	int i, j, k;
	// initialize
	for(i=1; i<=N; ++i){
		for(j=1; j<=N; ++j){
			dis[i][j] = INF;
		}
	}
	for(i=1; i<=N; ++i)
		dis[i][i] = 0;
	for(i=0; i<count; ++i){
		int s = contact[i][0];
		int f = contact[i][1];
		dis[s][f] = len[s][f];
	}

	// floyd
	for(k=1; k<=N; ++k){
		for(i=1; i<=N; ++i){
			for(j=1; j<=N; ++j){
				if(dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}

}


int main(){

	int i, j;
	int x, y, w, p;
	int id, tim;

	scanf("%d", &N);

	while(N != 0){
		for(i=1; i<=N; ++i){
			scanf("%d", &p);
			for(j=0; j<p; ++j){
				scanf("%d%d", &id, &tim);
				contact[count][0] = i;		
				contact[count][1] = id;
				count++;
				len[i][id] = tim;
			}
		}

		//printf("1\n");
		Floyd();
		//printf("2\n");
		int res_id;
		int res_tim = INF;
		int tmp;
		for(i=1; i<=N; ++i){
			tmp = 0;
			for(j=1; j<=N; ++j){
				if(tmp < dis[i][j]){
					tmp = dis[i][j];
				}
			}
			if(tmp < res_tim){
				res_tim = tmp;
				res_id = i;
			}
		}
		printf("%d %d\n", res_id, res_tim);

		for(i=0; i<count; ++i){
			contact[i][0] = 0;
			contact[i][1] = 0;
		}
		count = 0;
		
		scanf("%d", &N);
	}
	return 0;
}
