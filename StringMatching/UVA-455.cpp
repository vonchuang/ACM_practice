#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAX 105

using namespace std;

int failure[MAX];
int pos[MAX];
int cnt;
int N;

int MorrisPratt(string &t, string& p){
	int i, j;

	if(p.size() > t.size())
		return 0;

	for(i=0; i<t.size(); ++i)
		pos[i] = 0;
	cnt = 0;
	
	// calc failure function
	for(i=1, j=failure[0]=-1; i<p.size(); ++i){
		while(j>=0 && p[j+1]!=p[i])
			j = failure[j];
		if(p[j+1] == p[i])
			j++;
		failure[i] = j;
	}

	// string matching
	for(i=0,j=-1; i<t.size(); ++i){
		while(j>=0 && p[j+1]!=t[i])
			j = failure[j];
		if(p[j+1] == t[i])
			j++;

		// get p!
		if(j == p.size()-1){
//			cout << "p pos: " << i-p.size() +1<< endl;
			j = failure[j];
			if(cnt != 0 && (pos[cnt-1]+p.size() != i-p.size()+1)){
				return 0;
			}
			pos[cnt++] = i-p.size()+1;
		}
	}
//	printf("cnt %d\n", cnt);
	if(cnt*p.size() == t.size())
		return 1;
	else
		return 0;
}

int main(){
	int i, j;
	scanf("%d", &N);

	while(N--){
		string t;

		cin >> t;

		int flag = 0;
		for(i=1; i<=t.size(); ++i){
			string p;
			p = p.assign(t, 0, i);
//			cout << "p: " << p << endl;
			
			
			if(MorrisPratt(t, p) == 1){
//				cout << "res" << p.size() << endl;
				cout << p.size() << endl;
				flag = 1;
				break;
			}else{
//				cout << t.size() << endl;
			}
		}
		if(flag == 0)
			cout << t.size() << endl;

	
		if(N != 0){
			cout << endl;
//			cin >> t;
		}
			
	}

	return 0;
}
