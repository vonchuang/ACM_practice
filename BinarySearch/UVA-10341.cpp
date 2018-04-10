#include<cstdio>
#include<cmath>
#define MAX 1.0
#define MIN 0.0

using namespace std;

int p, q, r, s, t, u;

double BinarySearch(double left, double right){
	int i;
	double mid;
	for(i=0; i<100;++i){
	//while(left < right){
		mid = (left + right)/2;
		double y = p*exp(-mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*pow(mid,2)+u;
		//printf("l %lf, r %lf\n", left, right);
		if(fabs(y) < 1e-10)
			return mid;
		if(y > 0){
			left = mid;
		}else{
			right = mid;
		}
	}
	return -1;
}

int main(){

	while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF){
		double result = BinarySearch(0.0, 1.0);
		double check;
	
		//if(result < 0) result = -result;
		//check = p*exp(-result)+q*sin(result)+r*cos(result)+s*tan(result)+t*pow(result,2)+u;
		
		if(result == -1)
		//if(check-0 > 1e-10) 
			printf("No solution\n");
		
		else 
			printf("%.4lf\n", result);
		
	}

	return 0;
}

