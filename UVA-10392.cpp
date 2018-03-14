#include<cstdio>
#include<cstring>
#include<cmath>


#define MAX_SIZE 1000000

using namespace std;

bool is_prime[MAX_SIZE];

void eratosthenes(){
	int i, j;
	
	memset(is_prime, 1, sizeof(is_prime));

	is_prime[0] = false;
	is_prime[1] = false;

	for(i=2; i<=sqrt(MAX_SIZE); ++i){
		if(is_prime[i])
			for(j=i+i; j<MAX_SIZE; j+=i)
				is_prime[j] = false;
	
	}

}

int main(){
	long long int n, i;
	scanf("%lld", &n);

	eratosthenes();
	while(n > 0 ){
		for(i=2; i<MAX_SIZE; ++i){
			if(is_prime[i] == true){
				while(n%i == 0){
					printf("    %lld\n", i);
					n = n / i;
				}
			}
		}

		if(n != 1)
			printf("    %lld\n", n);

		scanf("%lld", &n);
		if(n > 0)
			printf("\n");
	
	}

	return 0;
}


