#include<stdio.h>
int n, k;
int t[500000];
int count=1;
void find(int step, int idx){
    if(step<=k&&idx!=1){
        find(step+1, t[idx]);
    }
    if(idx==1) count++;
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d", &num);
        for(int j=0;j<num;j++){
            int temp;
            scanf("%d", &temp);
            t[temp] = i;
        }
    }
    if(k>=n) count=n;
    else{
        for(int i=2;i<=n;i++){
            find(1, i);
        }
    }
    printf("%d\n", count);
    return 0;
}