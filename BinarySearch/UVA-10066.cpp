#include<cstdio>
#include<iostream>

#define MAX 102

using namespace std;

int na, nb;
int towa[MAX], towb[MAX];
int cnt[MAX][MAX];

int main(){

	int i, j;
	int num = 1;
	
	scanf("%d%d", &na, &nb);
	while(!(na == 0 && nb == 0)){
		// input
		for(i=1;i<=na;++i){
			scanf("%d", &towa[i]);
		}
		for(i=1;i<=nb;++i){
			scanf("%d", &towb[i]);
		}

		//initialize
		for(i=0;i<na;++i){
			for(j=0;j<nb;++j){
				cnt[i][j] = 0;
			}
		}

		//lcs
		for(i=1;i<=na;++i){
			for(j=1;j<=nb;++j){
				if(towa[i] == towb[j]){
					cnt[i][j] = cnt[i-1][j-1] + 1;
				}else{
					cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
				}
			}
		}
		
		// print result
		printf("Twin Towers #%d\n", num++);
		printf("Number of Tiles : %d\n\n", cnt[na][nb]);
		scanf("%d%d", &na, &nb);
	}

	return 0;
}
