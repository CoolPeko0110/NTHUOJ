#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define N 1000005

typedef struct Node{
    int idx;
    ll weight;
    struct Node *next;
}Node;

Node *child[N];
int n;
ll sum;
int been[N];
ll max=-1;
int startnode;

void dfs(int node, ll weight){
    if(weight>max){
        max=weight;
        startnode=node;
    }
    been[node]=1;
    Node *temp=child[node]->next;
    while(temp){
        if(!been[temp->idx]){
            dfs(temp->idx, weight+temp->weight);
        }
        temp=temp->next;
    }
}

void addnode(int father, int node, ll weight){
    Node *new=malloc(sizeof(Node));
    new->idx=node;
    new->weight=weight;
    new->next=child[father]->next;
    child[father]->next=new;
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
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        child[i]=malloc(sizeof(Node));
        child[i]->next=NULL;
        been[i]=0;
    }
    for(int i=0;i<n-1;i++){
        int a, b;
        ll w;
        scanf("%d %d %lld", &a, &b, &w);
        sum+=2*w;
        addnode(a, b, w);
        addnode(b, a, w);
    }
    dfs(0, 0);
    for(int i=0;i<n;i++) been[i]=0;
    dfs(startnode, 0);
    printf("%lld\n", sum-max);
    freenode();
    return 0;
}