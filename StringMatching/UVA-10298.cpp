#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAX 1000005

using namespace std;

int failure[MAX];

void MorrisPratt(string &t){
	int i, j, k, n;

	n = t.size();

	// calc failure function
	for(i=1, j=failure[0]=-1; i<=n; ++i){
		while(j>=0 && t[j+1]!=t[i])
			j = failure[j];
		if(t[j+1] == t[i])
			j++;
		failure[i] = j;
	}
	
	k = n - failure[n-1] - 1;

	if((n % k) == 0)
		cout << n/k << endl;
	else
		cout << 1 << endl;
}

int main(){
	int i, j;

	while(1){
		string t;

		cin >> t;
		if(t == ".")
			break;
			
		MorrisPratt(t);						

	}

	return 0;
}
