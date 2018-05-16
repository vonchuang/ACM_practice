#include<cstdio>
#include<string>
#include<iostream>

#define MAX 10

using namespace std;

int alen, blen;

int add(int a[MAX],int b[MAX]){
	int i;
	int c[MAX+1] = {0};
	int len = (alen>blen)? alen: blen;
	int cnt = 0;
	for(i=0; i<len; ++i)
		c[i] = a[i] + b[i];
	for(i=0; i<len; ++i){
		if(c[i]>9){
			cnt++;
			c[i+1] += c[i]/10;
			c[i] %= 10;
		}
	}

	return cnt;
}

int main(){
	string astr, bstr;
	int i;
	int a[MAX] = {0}, b[MAX] = {0};

	getline(cin, astr, ' ');
	getline(cin, bstr);
	while(!(astr == "0" && bstr == "0")){
		alen = (int)astr.length();
		blen = (int)bstr.length();

		// string to array
		for(i=0; i<alen; ++i)
			a[alen-i-1] = astr[i] - '0';
		for(i=0; i<blen; ++i)
			b[blen-i-1] = bstr[i] - '0';
	
		int res = add(a, b);
		if(res == 0)
			printf("No carry operation.\n");
		else if(res == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", res);

		
		// initialize
		for(i=0; i<alen; ++i)
			a[i] = 0;
		for(i=0; i<blen; ++i)
			b[i] = 0;
		
		getline(cin, astr, ' ');
		getline(cin, bstr);
	}

	return 0;
}
