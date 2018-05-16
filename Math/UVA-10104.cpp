#include<cstdio>

using namespace std;

long int exGCD(long int a, long int b, long int &X, long int &Y){
	if(b == 0){
		X = 1;
		Y = 0;
		return a;
	}else{
		int gcd = exGCD(b, a%b, X, Y);
		int tmp = X;
		X = Y;
		Y = tmp - (a/b)*Y;
		return gcd;
	}

}

int main(){
	long int a, b;
	long int x = 0, y = 1, d;

	while(scanf("%ld %ld", &a, &b) != EOF){
		d = exGCD(a, b, x, y);

		printf("%ld %ld %ld\n", x, y, d);

	}

	return 0;
}
