#include<stdio.h>
int main(){
    int t[200005];
    int n, k;
    scanf("%d %d", &n, &k);
    k=k%n;
    for(int i=0;i<=n;i++){
        t[i]=i+k;
        if(t[i]>n) t[i]=t[i]-n+1;
    }
    for(int i=0;i<n;i++){
        
    }
}