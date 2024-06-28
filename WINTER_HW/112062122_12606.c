#include<stdio.h>
int main(){
    int n;
    long long i, min=1000000001, max=-1;
    scanf("%d", &n);
    n++;
    while(n--){
        scanf("%lld", &i);
        if(i<min) min=i;
        if(i>max) max=i;
    }
    printf("%lld\n", 2*(max-min));
    return 0;
}