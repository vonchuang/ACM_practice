#include<cstdio>
#include<iostream>
#include<algorithm>

#define MAX 100

using namespace std;

string upper;
string edge;
int group[MAX];
int check[MAX];
int cnt = 0;
int range;
int N;

void CC(int A, int B){
    int i;
    int localMin = min(group[A], group[B]);
    int localMax = max(group[A], group[B]);
    
    
    for(i=0; i<=range; ++i){
        if(group[i] == localMax){
            group[i] = localMin;
        }
    }
    
}

void countGroup(){
    int i;
    for(i=0; i<=range; ++i){
        if(!check[group[i]]){
            check[group[i]] = 1;
            cnt++;
        }
    }
}

int main(){
	int i;
	scanf("%d", &N);

    while(N--){

		cin >> upper;	// max char
		range = upper[0] - 'A';

		for(i=0; i<= range; ++i){
			group[i] = i;
            check[i] = 0;
		}

		getline(cin, edge);
		while(getline(cin, edge) && edge != ""){
            int A = edge[0] - 'A';
            int B = edge[1] - 'A';
            
            CC(A, B);
			
		}

        cnt = 0;
        countGroup();
        
        printf("%d\n", cnt);
        if(N > 0)
            printf("\n");

	}

	return 0;
}
