#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define N 200005

typedef struct Node{
    int idx;
    ll weight;
    struct Node *next;
}Node;

Node *child[N];
ll number[N];
int been[N];
int n;
ll sum, avg, length;

void prepare(){
    sum=0;
    length=0;
    for(int i=0;i<n;i++){
        child[i]=malloc(sizeof(Node));
        child[i]->next=NULL;
        been[i]=0;
    }
    been[0]=1;
}

void addnode(Node* parent, int child, ll weight){
    Node *new = malloc(sizeof(Node));
    new->idx=child;
    new->weight=weight;
    new->next=parent->next;
    parent->next=new;
}

ll dfs(int parentnode, int node, ll weight){
    been[node]=1;
    ll num=number[node];
    if(!child[node]->next->next&&been[child[node]->next->idx]){
        length+=(num>0?num:-num)*weight;
        return num;
    }
    Node *temp=child[node]->next;
    while(temp){
        if(!been[temp->idx]){
            num+=dfs(node, temp->idx, temp->weight);
        }
        temp=temp->next;
    }
    length+=(num>0?num:-num)*weight;
    return num;
}

void freenode(){
    for(int i=0;i<n;i++){
        Node *temp=child[i];
        while(temp->next){
            Node *tmp=temp;
            temp=temp->next;
            free(tmp);
        }
        free(temp);
    }
}

int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        prepare(n);
        for(int i=0;i<n;i++){
            scanf("%lld", &number[i]);
            sum+=number[i];
        }
        if(sum%n){
            for(int i=0;i<n-1;i++){
                int a, b;
                ll w;
                scanf("%d %d %lld", &a, &b, &w);
            }
            freenode();
            printf("-1\n");
            continue;
        }
        avg=sum/n;
        for(int i=0;i<n;i++){
            number[i]-=avg;
        }
        for(int i=0;i<n-1;i++){
            int a, b;
            ll w;
            scanf("%d %d %lld", &a, &b, &w);
            addnode(child[a], b, w);
            addnode(child[b], a, w);
        }
        dfs(0, 0, 0);
        printf("%lld\n", length);
        freenode();
    }
    return 0;
}
