#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long num=9, count=0;
        while(num<b){
            count++;
            num=num*10+9;
        }
        printf("%lld\n", count*a);
    }
    return 0;
}