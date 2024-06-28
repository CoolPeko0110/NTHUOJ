#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int st1, st2;
char t1[1000005]={0}, t2[1000005]={0}; 
int parent[100005]={0}, p1[100005]={0}, p2[100005]={0};
int step1=0, step2=0;
int flag=1;
int N, n=0;
void check(int which, int father){
    if(which==1){
        if(n==N) return;
        int count=0;
        while(t1[step1]<='9'&&t1[step1]>='0'){
            count=count*10+(t1[step1]-'0');
            step1++;
        }
        parent[count]=father;
        n++;
        while(t1[step1]=='('||t1[step1]==')'){
            if(t1[step1]==')') p1[count]++;
            if(p1[count]==2) count=parent[count];
            step1++;
        }
        check(1, count);
    }
    else if(which==2){
        if(n==N||!flag) return;
        int count=0;
        while(t2[step2]<='9'&&t2[step2]>='0'){
            count=count*10+(t2[step2]-'0');
            step2++;
        }
        if(father!=parent[count]) flag=0;
        n++;
        while(t2[step2]=='('||t2[step2]==')'){
            if(t2[step2]==')') p2[count]++;
            if(p2[count]==2) count=parent[count];
            step2++;
        }
        check(2, count);
    }
}
int main(){
    scanf("%d", &N);
    scanf(" %s", t1);
    scanf(" %s", t2);
    check(1, 0);
    n=0;
    check(2, 0);
    if(flag) printf("YES");
    else printf("NO");
    return 0;
}