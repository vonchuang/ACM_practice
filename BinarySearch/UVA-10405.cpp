#include<cstdio>
#include<iostream>
#include<string>
#define MAX 1002

using namespace std;

string citia, citib;
int lena, lenb;
int cnt[MAX][MAX];

int main(){

	int i, j;

	//cin >> citia;
	while(getline(cin, citia)){
		//cin >> citib;
		getline(cin, citib);
		lena = citia.length();
		lenb = citib.length();

		//initialize
		for(i=0;i<=lena;++i){
			for(j=0;j<=lenb;++j){
				cnt[i][j] = 0;
			}
		}

		//lcs
		for(i=1;i<=lena;++i){
			for(j=1;j<=lenb;++j){
				if(citia[i-1] == citib[j-1]){
					cnt[i][j] = cnt[i-1][j-1] + 1;
				}else{
					cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
				}
			}
		}
		
		// print result
		printf("%d\n", cnt[lena][lenb]);
		
	//	cin >> citia;
	}

	return 0;
}
