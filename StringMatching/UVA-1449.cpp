#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAX 1000005
#define pMAX 200
using namespace std;

int failure[MAX];
int N;
int cnt[pMAX];

void MorrisPratt(string &t, string& p, int pos){
    int i, j;
    
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
            j = failure[j];
			cnt[pos]++;
		}
    }
    //    printf("cnt %d\n", cnt);
}

int main(){
	int i, j;
	string p[pMAX];
	string t;

	scanf("%d", &N);
	while(N != 0){
		int ans = 0;
		for(i=0; i<N; ++i){
			cin >> p[i];
			cnt[i] = 0;
		}
		cin >> t;
		
		for(i=0; i<N; ++i)
			MorrisPratt(t, p[i], i);


		for(i=0; i<N; ++i){
			if(cnt[i] > ans)
				ans = cnt[i];
		}
		
		cout << ans << endl;
			
		for(i=0; i<N; ++i){
			if(cnt[i] == ans)
				cout << p[i] << endl;
		}
		
		scanf("%d", &N);
	}

	return 0;
}
