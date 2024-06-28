/*
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *next; 
}node;
node *head;
void ADD(int pos, int value){
    if(pos==0){
        node *new=(node*)malloc(sizeof(node));
        new->val=value;
        new->next=head;
        head=new;
    }
    else{
        node *temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        node *new=(node*)malloc(sizeof(node));
        new->val=value;
        new->next=temp->next;
        temp->next=new;
    }
}
void CUT(int left, int right){
    if(left==0) return;
    node *temp=head;
    node *tmp=(node*)malloc(sizeof(node));
    node *tp=(node*)malloc(sizeof(node));
    for(int count=0;count<right-1;count++){
        if(count==left-1){
            tmp=temp;
            tp=tmp->next;
        }
        temp=temp->next;
    }
    tmp->next=temp->next;
    temp->next=head;
    head=tp;
}
int main(){
    char com[5]={0};
    int n, k, a, b; scanf("%d %d", &n, &k);
    head=(node*)malloc(sizeof(node));
    scanf("%d", &(head->val));
    head->next=NULL;
    node *temp=head;
    for(int i=0;i<n;i++){
        node *new=(node*)malloc(sizeof(node));
        scanf("%d", &(new->val));
        new->next=temp->next;
        temp->next=new;
        temp=new;
    }
    for(int i=0;i<k;i++){
        scanf(" %s %d %d", com, &a, &b);
        if(com[0]=='A') ADD(a, b);
        else CUT(a, a+b);
    }
    while(head->next!=NULL){
        printf("%d\n", head->val);
        head=head->next;
    }
    return 0;
}
*/

/*
#include"function.h"
#include<stdio.h>
#include<stdlib.h>
Node* createList(int n){
    head=(Node*)malloc(sizeof(Node));
    head->number=1;
    Node *temp=head;
    for(int i=2;i<=n;i++){
        Node *new=(Node*)malloc(sizeof(Node));
        new->number=i;
        new->prev=temp;
        temp->next=new;
        temp=new;
    }
    head->prev=temp;
    temp->next=head;
    Node *tmp=head;
    return head;
}
void solveJosephus(int n, int k){
    for(int i=0;i<k;i++){
        int lucky; scanf("%d", &lucky);
        if(lucky%2){
            if(!i) lucky--;
            lucky%=n;
            if(!lucky) lucky+=n;
            while(lucky--) head=head->next;
        }
        else{
            if(!i) lucky--;
            lucky%=n;
            if(!lucky) lucky+=n;
            while(lucky--) head=head->prev;
        }
        printf("%d\n", head->number);
        head->prev->next=head->next;
        head->next->prev=head->prev;
        n--;
    }
}
*/
/*
#include"function.h"
#include<stdio.h>
#include<stdlib.h>
ListNode* mergeLinkedList(ListNode* lhs, ListNode* rhs){
    ListNode* ptr;
	if(lhs->val>rhs->val){
        ptr=rhs;
        rhs=rhs->next;
    }
    else{
        ptr=lhs;
        lhs=lhs->next;
    }
    ListNode* cur=ptr;
    while(lhs!=NULL&&rhs!=NULL){
        if(lhs->val>rhs->val){
            cur->next=rhs;
            rhs=rhs->next;
        }
        else{
            cur->next=lhs;
            lhs=lhs->next;
        }
        cur=cur->next;
    }
    if(lhs==NULL) cur->next=rhs;
    else cur->next=lhs;
    return ptr;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}Node;
int main(){
    int n, k; scanf("%d %d", &n, &k);
    Node *head=(Node*)malloc(sizeof(Node));
    head->val=1;
    head->next=NULL;
    Node *temp=head;
    for(int i=2;i<=n;i++){
        Node *new=(Node*)malloc(sizeof(Node));
        new->val=i;
        new->next=temp->next;
        temp->next=new;
        temp=temp->next;
    }
    temp->next=head;
    temp=head;
    int num=n;
    for(int i=0;i<num;i++){
        int count=k%n;
        if(count<=0) count+=n;
        int step=count;
        while(--count) temp=temp->next;
        printf("%d ", temp->next->val);
        temp->next=temp->next->next;
        temp=temp->next;
        n--;
    }
    return 0;
}
*/