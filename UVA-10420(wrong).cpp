#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#define MAX_SIZE 2000

using namespace std;
string country[2000];
//int countNum[2000] = {0};

int main(){
	int i, j;
	int index = 0;	// how many country
    int n, name;
	char *str;
	char token[] = " ", *ptr;

	scanf("%d", &n);
	gets(str);
	// each line
	for(i = 0; i < n; ++i){
		gets(str);
		name = 1;
		//each word
		for(ptr = strtok(str, token); ptr; ptr = strtok(NULL, token)){
			// country name
			if(name == 1){
				/*
				int check = 0;
				for(j = 0; j < index; ++j){
					// already have the country
					if(strcmp(country[j].c_str(), ptr) == 0){
						countNum[j]++;
						check = 1;
						break;
					}
				}
				
				// the first person in sertain country
				if(check == 0){
					//strncpy(country[index++], ptr, sizeof(country[index]));
					country[index].append(ptr);
					countNum[index] = 1;
					index++;
				}
				*/
				country[index++].append(ptr);
				break;
			}
			name++;
		}
	}

	//sort(country, country+index+1);

	for(i = 0; i < index; ++i){
		//printf("%s %d\n", country[i], countNum[i]);
		printf("%s\n", country[i]);
	}

	return 0;
}
