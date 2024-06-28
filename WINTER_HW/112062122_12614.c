#include<stdio.h>
int main(){
    int n, m;
    int g[1005], b[1005];
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &g[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d", &b[i]);
    }
    int i=0, j=0;
    int count=0;
    while(i<n&&j<m){
        if(g[i]>b[j]) i++;
        else{
            count++;
            i++;
            j++;
        } 
    }
    printf("%d\n", count);
    return 0;
}