#include<stdio.h>
int n, arr[10005]={0};
int count=0, time=0;
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int *begin, int *end)
{
    for (; begin < end; end--){
        int c=0;
        for (int *ptr = begin + 1; ptr < end; ptr++){
            time++;
            if (*(ptr - 1) > *ptr){
                c++;
                swap(ptr - 1, ptr);
            }
        }
        if(!c) break;
        count+=c;
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    bubble_sort(&arr[0], &arr[n]);
    printf("%d %d\n", time, count);
    return 0;
}