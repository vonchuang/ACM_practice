#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAX 1000005

using namespace std;

int failure[MAX];
int N;
int sub;

int MorrisPratt(string &t, string& p){
    int i, j;
    
    if(p.size() > t.size())
        return 0;
    
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
			return 1;
		}
    }
    //    printf("cnt %d\n", cnt);
    return 0;
}

int main(){
	int i, j;
	
	scanf("%d", &N);
	while(N--){
		string t;

		cin >> t;
		scanf("%d", &sub);
		for(i=0; i<sub; ++i){
			string p;
			cin >> p;

			if(MorrisPratt(t, p))
				printf("y\n");
			else
				printf("n\n");
		}

	}

	return 0;
}
