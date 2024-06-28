#include<stdio.h>
#include <stdlib.h>
typedef struct node{
    int x;
    struct node *next;
} Node;
void cut(int a, int b, Node **head){
    if(a==0) return;
    Node *tp = *head;
    Node *temp = *head;
    int count=0;
    while(count+1<a){
        temp=temp->next;
        count++;
    }
    Node *tmp = temp;
    temp = temp->next;
    *head = temp;
    //printf("%d %d\n", tmp->x, temp->x);
    while(count<a+b-2){
        temp=temp->next;
        count++;
    }
    tmp->next = temp->next;
    temp->next = tp;
}
void add(int idx, int n, Node **head){
    Node *new = (Node*)malloc(sizeof(Node));
    int count=0;
    new->x = n;
    Node *temp = *head;
    if(idx==0){
        new->next=*head;
        *head=new;
    }
    else{
        while(count+1<idx){
            temp=temp->next;
            count++;
        }
        new->next = temp->next;
        temp->next = new;
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Node *head = (Node*)malloc(sizeof(Node));
    int num;
    scanf("%d", &num);
    head->x=num;
    head->next=NULL;
    n--;
    Node *temp=head;
    while(n--){
        scanf("%d", &num);
        Node *new = (Node*)malloc(sizeof(Node));
        new->x=num;
        temp->next=new;
        temp=new;
    }
    temp->next=NULL;
    /*
    while(temp!=NULL){
        printf("%d\n", temp->x);
        temp=temp->next;
    }
    */
    char com[5];
    int a, b;
    while(m--){
        scanf(" %s %d %d", com, &a, &b);
        if(com[0]=='A') add(a, b, &head);
        else cut(a, b, &head);
    }
    temp=head;
    while(temp!=NULL){
        printf("%d\n", temp->x);
        temp=temp->next;
    }
    return 0;
}