#include<stdio.h>
short size;
short grid[15][15]={0};
int count;
_Bool check(int x, int y){
    for(int k=x-1, j=y-1;k>=1&&j>=1;k--, j--){
        if(grid[k][j]==-1) return 0;
    }
    for(int k=x+1, j=y-1;k<=size&&j>=1;k++, j--){
        if(grid[k][j]==-1) return 0;
    }
    return 1;
}
void place(int step, int nqueen, int nking){
    for(int i=1;i<=size;i++){
        if(grid[i][step]==0){
            if(step==size){
                if(nqueen>0&&check(i, step)) count++;
                if(nking>0) count++;
            }
            if(nqueen>0&&check(i, step)){
                grid[i][step]=-1;
                for(int j=step+1;j<=size;j++) grid[i][j]++;
                for(int k=i-1, j=step+1;k>=1&&j<=size;k--, j++) grid[k][j]++;
                for(int k=i+1, j=step+1;k<=size&&j<=size;k++, j++) grid[k][j]++;
                if(step<size) place(step+1, nqueen-1, nking);
                grid[i][step]=0;
                for(int j=step+1;j<=size;j++) grid[i][j]--;
                for(int k=i-1, j=step+1;k>=1&&j<=size;k--, j++) grid[k][j]--;
                for(int k=i+1, j=step+1;k<=size&&j<=size;k++, j++) grid[k][j]--;
            }
            if(nking>0){
                grid[i][step]=-1;
                for(int j=step+1;j<=size;j++) grid[i][j]++;
                if(step<size) place(step+1, nqueen, nking-1);
                grid[i][step]=0;
                for(int j=step+1;j<=size;j++) grid[i][j]--;
            }
        }
    }
}
int main(){
    short n, m;
    while(scanf("%hi %hi", &n, &m)!=EOF){
        count=0;
        size=n+m;
        place(1, n, m);
        printf("%d\n", count);
    }
    return 0;
}