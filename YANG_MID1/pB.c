#include<stdio.h>
#include<stdlib.h>
/*
7
0 0
1 3
0 0
2 6
0 0
5 7
0 0
*/
int node[100001][2]={0};
int parent[100001]={0};
int fx=0;
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void print(int root){ 
    if(node[root][0]) print(node[root][0]);
    if(node[root][1]) print(node[root][1]);
    if(!fx){
        printf("%d", root);
        fx++;
    }
    else printf(" %d", root);
}
int main(){
    int n;
    int flag;
    while(scanf("%d", &n)!=EOF){
        flag = 1;
        fx=0;
        for(int i=0;i<=n;i++){
            node[i][0] = 0;
            node[i][1] = 0;
            parent[i]=0;
        }
        for(int i=1;i<=n;i++){
            int a, b, min, max;
            scanf("%d %d", &a, &b);
            if((!a&&b&&b<i)||(!b&&a&&a>=i)||(a>b&&a&&b)) swap(&a, &b);
            node[i][0] = a;
            node[i][1] = b;
            if((a&&a>=i)||(b&&b<=i)){
                flag = 0;
            }
            parent[a]=i;
            parent[b]=i;
        }
        if(flag){
            printf("YES\n");
            int root;
            for(int i=1;i<=n;i++){
                if(!parent[i]){
                    root=i;
                    break;
                }
            }
            print(root);
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}