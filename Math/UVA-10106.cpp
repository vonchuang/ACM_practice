#include<cstdio>
#include<string>
#include<iostream>

#define MAX 250

using namespace std;

int alen, blen;

void multi(int a[MAX],int b[MAX], int c[MAX*2]){
	int i, j;
	for(i=0; i<alen; ++i){
		for(j=0; j<blen; ++j){
			c[i+j] += a[i] * b[j];
//			printf("%d ",c[i+j]);
		}
//		printf("\n");
	}

	for(i=0; i<(alen+blen); ++i){
		c[i+1] += c[i]/10;
		c[i] %= 10;
	}
}

int main(){
	string astr, bstr;
	int i;
	int a[MAX] = {0}, b[MAX] = {0}, c[MAX*2] = {0};

	while(getline(cin, astr)){
		getline(cin, bstr);
		alen = (int)astr.length();
		blen = (int)bstr.length();
		//printf("%d\n", len);

		// string to array
		for(i=0; i<alen; ++i)
			a[alen-i-1] = astr[i] - '0';
		for(i=0; i<blen; ++i)
			b[blen-i-1] = bstr[i] - '0';
		
		if((alen == 1 && a[0] == 0) || (blen == 1 && b[0] == 0)){
			printf("0\n");
		}else{
			// multi
			multi(a, b, c);

			for(i=0; i<(alen+blen); ++i){
				if(i == 0 && c[alen+blen-1-i] == 0){
					;
				}else{
					printf("%d", c[alen+blen-1-i]);
				}
			}
			printf("\n");
		}
		// initialize
		for(i=0; i<alen; ++i)
			a[i] = 0;
		for(i=0; i<blen; ++i)
			b[i] = 0;
		for(i=0; i<(alen+blen); ++i)
			c[i] = 0;
	}

	return 0;
}
