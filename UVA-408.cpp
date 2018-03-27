#include<cstdio>

//#define MAX 1000001

using namespace std;

int step, mod;
//int check[MAX] = {0};

int gcd(int a, int b){
	
	if(a == 0){
		//check[a] = 1;
		return b;
	}
	/*
	if(check[a] == 1){
		return b;
	}
	*/
//	printf("%d ", a);
	//check[a] = 1;
	//return gcd((a + step)%b, b);
	return gcd(b%a, a);
}

int main(){
	int i, first = 1;

	while(scanf("%d %d", &step, &mod) != EOF){
		/*
		if(first == 1)
			first = 0;
		else
			printf("\n");
		*/
		int res = gcd(step, mod);

		/*
		int tmp = 1;
		for(i=0; i<mod; ++i){
			//printf("%d ", check[i]);
			if(check[i] == 0){
				tmp = 0;
				break;
			}
		}
		*/
//		printf("\n");
		if(res != 1){
			printf("%10d%10d    Bad Choice\n", step, mod);
		}else{
			printf("%10d%10d    Good Choice\n", step, mod);
		}
		printf("\n");
		
		//for(i=0; i<MAX; ++i)
		//	check[i] = 0;
	}

	return 0;
}
