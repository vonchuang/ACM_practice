#include<cstdio>
#include<cstdlib>

#define MAX_SIZE 10000

using namespace std;

long int array[MAX_SIZE];
long int combined[MAX_SIZE];
int index = 0;

void Merge(long int list[], int low, int high){
    int k = 0, mid = (low + high)/2;
    int i = low, j = mid + 1;
    
    while(i <= mid && j <= high){
        if(list[i] < list[j])
            combined[k++] = list[i++];
        else{
            combined[k++] = list[j++];
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
    if(low < high){
        MergeSort(list, low, (low + high)/2);
        MergeSort(list, (low + high)/2 + 1, high);
        Merge(list, low, high);
    }
}

int main(){
	int nu;

	while(scanf("%d", &nu) != EOF){
		array[index] = nu;
		MergeSort(array, 0, index);	
		
		if((index+1)%2 == 0){	//even numbers
			printf("%ld\n", (array[index/2] + array[index/2+1])/2);
		}else{	// odd numbers
			printf("%ld\n", array[index/2]);
		}

		index++;
	}


	return 0;
}
