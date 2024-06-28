#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    long long x[200005]={}, able[200005]={};
    char direction[200005]={};
    for(int i=0;i<n;i++){
        scanf(" %c", &direction[i]);
        if(direction[i]=='L'&&direction[i-1]=='R'){
            able[i]=1;
        }
    }
    long long min=1000000001;
    for(int i=0;i<n;i++){
        scanf("%lld", &x[i]);
        if(able[i]) if(x[i]-x[i-1]<min&&(x[i]-x[i-1])%2==0) min = x[i]-x[i-1];
    }
    if(min==1000000001) printf("-1\n");
    else printf("%lld\n", min/2);
    return 0;
}