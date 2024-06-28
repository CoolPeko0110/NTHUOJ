#include<stdio.h>
int w[1005], val[1005], m[1005][1005]={0};
int main(){
    int n, c;
    scanf("%d %d", &n, &c);
    for(int i=1;i<=n;i++) scanf("%d %d", &val[i], &w[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(w[i]<=j){
                if(val[i]+m[j-w[i]][i-1]>=m[j][i-1]) m[j][i]=val[i]+m[j-w[i]][i-1];
                else m[j][i]=m[j][i-1];
            }
            else m[j][i]=m[j][i-1];
        }
    }
    printf("%d\n", m[c][n]);
    return 0;
}