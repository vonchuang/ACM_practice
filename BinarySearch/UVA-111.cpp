#include<cstdio>
#include<iostream>

#define MAX 22

using namespace std;

int n;
int ans[MAX], stu[MAX], lcs[MAX];
int cnt[MAX][MAX];

int main(){

	int i, j, pos;
	
	
	scanf("%d", &n);

	// input ans
	for(i=1;i<=n;++i){
		scanf("%d", &pos);
		ans[pos] = i;
	}


	while(scanf("%d", &pos) != EOF){
		stu[pos] = 1;
		// input
		for(i=2;i<=n;++i){
			scanf("%d", &pos);
			stu[pos] = i;
		}

		//initialize
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				cnt[i][j] = 0;
			}
		}

		//lcs
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				if(stu[i] == ans[j]){
					cnt[i][j] = cnt[i-1][j-1] + 1;
				}else{
					cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
				}
			}
		}
		
		// print result
		printf("%d\n", cnt[n][n]);
	}

	return 0;
}
