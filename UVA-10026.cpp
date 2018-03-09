#include<cstdio>
#include<algorithm>

#define MAX_SIZE 1000

using namespace std;

struct Order{
	float num;
	int pos;
}ft[MAX_SIZE];

bool cmp(struct Order p1, struct Order p2){
	return p1.num > p2.num;
}

int main(){

	int caseNum, n;
	int time[MAX_SIZE], fine[MAX_SIZE];
	int i;

	scanf("%d", &caseNum);	// how many case
	//printf("\n");

	while(caseNum--){
		getchar();
		scanf("%d", &n);	// how many job
		for(i=0;i<n;++i){
			scanf("%d", &time[i]);
			scanf("%d", &fine[i]);
			ft[i].num = (float)fine[i]/(float)time[i];
			ft[i].pos = i+1;
		}

		// sort
		sort(ft, ft+n, cmp);

		// print result
		for(i=0;i<n;++i){
			printf("%d",ft[i].pos);
			if(i < n-1) printf(" ");
		}
		printf("\n");
		//initialize
		for(i=0;i<n;++i){
			ft[i].num = 0;
			ft[i].pos = 0;
			time[i] = 0;
			fine[i] = 0;
		}

		if(caseNum > 0){
			printf("\n");
			getchar();
		}
	}


	return 0;
}
