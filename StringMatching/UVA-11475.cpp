#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAX 100005

using namespace std;

int failure[MAX];
int pos[MAX];
int cnt;
int N;

void MorrisPratt(string &t){
	int i, j;
	string tRev = t;

	for(i=0; i<t.size(); ++i)
		pos[i] = 0;
	cnt = 0;
	
	for(i=0; i<t.size();++i)
		tRev[i] = t[t.size()-1-i];

	// calc failure function
	for(i=1, j=failure[0]=-1; i<tRev.size(); ++i){
		while(j>=0 && tRev[j+1]!=tRev[i])
			j = failure[j];
		if(tRev[j+1] == tRev[i])
			j++;
		failure[i] = j;
	}

	// string matching
	for(i=0,j=-1; i<t.size(); ++i){
		while(j>=0 && t[i]!=tRev[j+1])
			j = failure[j];
		if(t[i] == tRev[j+1])
			j++;
	}
	cout << t ;
	for(i=j+1; i<tRev.size(); ++i)
		cout << tRev[i];
	cout << endl;

}

int main(){
	int i, j;
	string t;

	while(cin >> t){


		MorrisPratt(t);
			
	}

	return 0;
}
