#include<stdio.h>
int n, l, r;
long long len[51], m[51];
int find(int n, int index){
    if(index==0) return 0;
    else if(index==m[n]) return 1;
    else if(index==len[n]) return 2;
    else if(index<m[n]) return find(n-1, index-1);
    else return find(n-1, index-m[n]-1);
}
int main(){
    len[1]=2;
    m[1]=1;
    for(int i=2;i<=50;i++){
        len[i]=2*(len[i-1]+1)+3-1;
        m[i]=len[i]/2;
    }
    while(scanf("%d %d %d", &n, &l, &r)!=EOF){
        for(int i=l;i<=r;i++){
            if(find(n, i)==0) printf("O");
            if(find(n, i)==1) printf("u");
            if(find(n, i)==2) printf("Q");
        }
        printf("\n");
    }
    return 0;
}