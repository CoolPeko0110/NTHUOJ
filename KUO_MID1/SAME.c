#include<stdio.h>
#include<stdlib.h>
char t[1000005]={0};
int re[100005][2]={0}, pa[100005]={0}, pos=0;
int N, n=0;
int main(){
    scanf("%d", &N);
    scanf(" %s", t);
    int T, d, comm, com;
    scanf("%d", &T);
    int count=0;
    int father=0;
    while(n<N){
        while(t[pos]<='9'&&t[pos]>='0'){
            count=count*10+t[pos]-'0';
            pos++;
        }
        n++;
        if(!re[father][0]) re[father][0]=count;
        else re[father][1]=count;
        pa[count]=father;
        int count1=0, count2=0;
        while(t[pos]=='('||t[pos]==')'){
            if(t[pos]=='(') count1++;
            else count2++;
            if(count2>count1) count=pa[count]; 
            pos++;
        }
        father=count;
        count=0;
    }
    while(T--){
        int flag=1;
        scanf("%d", &d);
        scanf("%d", &comm);
        for(int i=0;i<d-1;i++){
            scanf("%d", &com);
            if(com!=re[comm][0]&&com!=re[comm][1]) flag=0;
            printf("%d %d\n", comm, com);
            comm=com;
        }
        if(!flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}