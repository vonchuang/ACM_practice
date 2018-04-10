#include<cstdio>
#include<string>
#include<iostream>

#define MAX 102

using namespace std;

string stra[MAX], strb[MAX], lcs[MAX];
int cnt[MAX][MAX], prevcnt[MAX][MAX];

void printLCS(int i, int j){
	int len = cnt[i][j];
	int lena = i, lenb = j;
	int k;
	//while(i && j){
	while(len>0){
		if(prevcnt[i][j] == 0){	//left up
//			cout<<"LU ";
			len--;
			lcs[len] = stra[i];
			i--;
			j--;
		}else if(prevcnt[i][j] == 1){	//left
//			cout<<"L";
			j--;
		}else if(prevcnt[i][j] == 2){	// up
//			cout<<"U ";
			i--;
		}
	}

	len = cnt[lena][lenb];
	for(k=0;k<len;++k){
		cout<<lcs[k];
		if(k<len-1)	cout<<" ";
		else	cout<<endl;
	}
	//cout<<endl;
}

int main(){

	int i, j;
	int lena = 1, lenb;
	while(cin>>stra[lena++]){
		//initialize
		for(i=0;i<MAX;++i){
			for(j=0;j<MAX;++j){
				cnt[i][j] = 0;
				prevcnt[i][j] = 0;
			}
		}

		// input
		//cin >> stra[lena++];
		while(stra[lena-1] != "#"){
			cin >> stra[lena++];
		}
		lena--;

		lenb = 1;
		cin >> strb[lenb++];
		while(strb[lenb-1] != "#"){
			cin >> strb[lenb++];
		}
		lenb--;

		//lcs
		for(i=1;i<=lena;++i){
			for(j=1;j<=lenb;++j){
				if(stra[i] == strb[j] && stra[i] != "#"){
//						cout<<"0 "<<stra[i]<<endl;
					cnt[i][j] = cnt[i-1][j-1] + 1;
					prevcnt[i][j] = 0;	// left up
				}else{
					if(cnt[i-1][j] < cnt[i][j-1]){
//						cout<<"1"<<endl;
						cnt[i][j] = cnt[i][j-1];
						prevcnt[i][j] = 1;	// left
					}else{
//						cout<<"2"<<endl;
						cnt[i][j] = cnt[i-1][j];
						prevcnt[i][j] = 2;	// up
					}
				}
			}
		}

//		printf("lcs: %d\n", cnt[lena][lenb]);
		printLCS(lena, lenb);
		lena = 1;
	}

	return 0;
}
