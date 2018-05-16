#include<cstdio>


using namespace std;

int step, mod;

int gcd(int a, int b){
	
	if(a == 0){
		return b;
	}
	return gcd(b%a, a);
}

int main(){
	int i, first = 1;

	while(scanf("%d %d", &step, &mod) != EOF){

		int res = gcd(step, mod);

		if(res != 1){
			printf("%10d%10d    Bad Choice\n", step, mod);
		}else{
			printf("%10d%10d    Good Choice\n", step, mod);
		}
		printf("\n");
		
	}

	return 0;
}
