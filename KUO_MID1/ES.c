#include<stdio.h>
#include<stdlib.h>
long long s[10005]={0};
long long count=0;
int cmpfunc (const void * a, const void * b){
   return ( *(long long*)a - *(long long*)b );
}
int main(){
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%lld", &s[i]);
    qsort(s, n, sizeof(long long), cmpfunc);
    for(int i=0;i<n-1;i++){
        int j=i;
        while(s[j]>s[j+1]&&j<n-1){
            long long temp=s[j];
            s[j]=s[j+1];
            s[j+1]=temp;
            j++;
        }
        s[i+1]=s[i]+s[i+1];
        s[i]=0;
        count+=s[i+1];
    }
    printf("%lld", count);
    return 0;
}