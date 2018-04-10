#include<cstdio>
#include<iostream>
#include<string>
#define MAX 32

using namespace std;

string citia, citib;
int lena, lenb;
int cnt[MAX][MAX];
int uni[MAX][MAX];

int main(){

	int i, j, n;
	int num = 1;
	char line;
	
	scanf("%d", &n);
	scanf("%c", &line);
	//cin >> citia;
	while(n--){
		getline(cin, citia);
		getline(cin, citib);
		
		lena = citia.length();
		lenb = citib.length();

		//initialize
		for(i=0;i<=lena;++i){
			for(j=0;j<=lenb;++j){
				cnt[i][j] = 0;
				uni[i][j] = 1;
			}
		}

		//lcs
		for(i=1;i<=lena;++i){
			for(j=1;j<=lenb;++j){
				if(citia[i-1] == citib[j-1]){
					cnt[i][j] = cnt[i-1][j-1] + 1;
					uni[i][j] = uni[i-1][j-1];
				}else{
					cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
					if(cnt[i-1][j] < cnt[i][j-1]){	// left
						uni[i][j] = uni[i][j-1];
					}else if(cnt[i-1][j] > cnt[i][j-1]){	// up
						uni[i][j] = uni[i-1][j];
					}else{
						uni[i][j] = uni[i-1][j] + uni[i][j-1];
					}

				}
			}
		}
		
		// print result
		printf("Case #%d: %d %d\n", num++, lena + lenb - cnt[lena][lenb], uni[lena][lenb]);
		
	//	cin >> citia;
	}

	return 0;
}
