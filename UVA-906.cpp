#include<cstdio>

#define MAX 100000
#define eps 1e-8

using namespace std;

int main(){
	int a, b, c, d;
	int i, j;
	int check = 0;
	double adivb, cdivd, distance;
	double n;
	

	while(scanf("%d %d", &a, &b) != EOF){
		scanf("%lf", &n);
		adivb = (double)a/(double)b;

		for(i=1; i<MAX; ++i){	// d
			for(j=(i*adivb-1); j>0, j<(i*adivb)+1, j<i; ++j){	// c
			//for(j=1; j<i; ++j){	// c
				cdivd = (double)j / (double)i;
				if(adivb > cdivd)
					distance = adivb - cdivd;
				else
					distance = cdivd - adivb;

				if((adivb < cdivd) && ((n-distance) > eps)){
					c = j;
					d = i;
					check = 1;
					break;
				}
			
			}
			if(check == 1)
				break;
		
		}	

		check = 0;
		printf("%d %d\n", c, d);
	
	}




	return 0;
}
