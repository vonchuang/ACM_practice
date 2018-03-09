/*****************************************
 * Name: vonchuang
 * Description: UVA-10810
 * Date: 2018.3.7
******************************************/
#include <cstdlib>
#include <cstdio>

#define MAX_SIZE 500000
using namespace std;

long long int op = 0;
long int list[MAX_SIZE] = {0};
long int combined[MAX_SIZE];

void Merge(long int list[], int low, int high){
	//printf("Merge low = %d, high = %d\n", low, high);
	int k = 0, mid = (low + high)/2;
	int i = low, j = mid + 1;

	while(i <= mid && j <= high){
		if(list[i] < list[j])
			combined[k++] = list[i++];
		else{
			combined[k++] = list[j++];
			//op++;
			//op += (j - k);
			op += mid - i + 1;
		}
	}

	while(i <= mid){
		combined[k++] = list[i++];
	}
	while(j <= high){
		combined[k++] = list[j++];
	}
	for(i = low, j = 0; i <= high; i++, j++)
		list[i] = combined[j];
}

void MergeSort(long int list[], int low, int high){
	//printf("MergeSort low = %d, high = %d\n", low, high);
	if(low < high){
		MergeSort(list, low, (low + high)/2);
		MergeSort(list, (low + high)/2 + 1, high);
		Merge(list, low, high);
	}
}

int main(){
	int i, n;
	scanf("%d", &n);

	while(n != 0){
		for(i = 0; i< n; ++i)
			scanf("%ld", &list[i]);
		MergeSort(list, 0, n-1);
		printf("%lld\n", op);

		op = 0;
		for(i = 0; i < MAX_SIZE; ++i){
			list[i] = 0;
			combined[i] = 0;
		}
		scanf("%d", &n);
	}
	return 0;
}
