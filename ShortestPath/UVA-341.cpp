#include<cstdio>

#define MAX 1005
#define TMAX 2005
using namespace std;

int dis[MAX];
int trace[MAX];
int len[MAX][MAX];
int contact[TMAX][2];
int count = 0;
int N;

void Relax(int u, int v){
	if(dis[u]+len[u][v] < dis[v]){
		dis[v] = dis[u] + len[u][v];
		trace[v] = u;
	}
}

void BellmanFord(int s){
	int i, j, k;
	// initialize
	for(i=1; i<=N; ++i){
		dis[i] = 999999;
		trace[i] = 0;
	}
	dis[s] = 0;

	// relax
	for(i=1; i<N; ++i){
		for(j=0; j<count; ++j){
			Relax(contact[j][0], contact[j][1]);
		}
	}

}
void setContact(int x, int y, int w){
    int i, flag=0;
    for(i=0; i<count; ++i){
        if(contact[i][0]==x && contact[i][1]==y){
            flag = 1;
            if(w < len[x][y]){
                len[x][y] = w;
            }
        }
    }
    
    if(flag == 0){
        contact[count][0] = x;
        contact[count][1] = y;
        count++;
        len[x][y] = w;
    }
}

int main(){

	int i, j;
	int f, w, p, s;
	int cnt = 1;

	scanf("%d", &N);

	while(N != 0){
		for(i=0; i<count; ++i){
			contact[i][0] = 0;
			contact[i][1] = 0;
		}
		count = 0;
		
		for(i=1; i<=N; ++i){
			scanf("%d", &p);
			for(j=0; j<p; ++j){
				scanf("%d%d", &f, &w);
                setContact(i, f, w);
                /*
				contact[count][0] = i;		
				contact[count][1] = f;
				count++;
				len[i][f] = w;
                 */
			}
		}
		scanf("%d%d", &s, &f);

		BellmanFord(s);

		printf("Case %d: Path = %d", cnt++, s);

		int res[MAX] = {0};
		int index = 0;
		i = trace[f];
		while(i != s){
			res[index++] = i;
			i = trace[i];
		}
		for(i=index-1; i>=0; --i){
			printf(" %d", res[i]);
		}
		printf(" %d; %d second delay\n", f, dis[f]);



		scanf("%d", &N);
	}

	return 0;
}
