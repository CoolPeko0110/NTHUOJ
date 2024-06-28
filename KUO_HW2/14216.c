#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flag=0;
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}

int* rearrange(int* begin, int* end, int* pivot){
    if(flag){
        flag=0;
        return begin+(end-begin)/2;
    }
    int val=*pivot;
    if(pivot!=end-1) swap(end-1, pivot);
    int *left=begin, *right=end-2;
    int *temp=begin+1;
    for(;right>=begin;right--){
        while(*left<=val&&left<right) left++;
        if(*right<=val) swap(left, right);  
        if(right==left) break;  
    }
    while(*left<=val&&left<end-1) left++; 
    swap(end-1, left);
    return left;
}

int* pickPivot(int* begin, int* end){
    int count=0;
    int *temp=begin+1;
    for(;temp<end;temp++){
        if(*temp<*(temp-1)){
            count++;
        }
    }
    if(!count){
        flag=1;
        return begin+(end-begin)/2;
    }
    srand( time(NULL) );
    return begin+rand()%(end-begin);
}

void qsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    exit(1);
}

void quickSort(int* begin, int* end) {
    if (end - begin <= 1) return;

    int* mid = rearrange(begin, end, pickPivot(begin, end));
    quickSort(begin, mid);
    quickSort(mid + 1, end);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);

    quickSort(arr, arr + n);

    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}
