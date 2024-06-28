#include"function.h"
#include <stdlib.h>
#include <stdio.h>

void deleteNode(Node ** nd, int data){
    int n = 1;
    Node *now = *nd;
    if(data==1&&(*nd)!=NULL){
        (*nd)=(*nd)->next;
        free(now);
        return;
    }
    else{
        while(now!=NULL&&now->next!=NULL){
            if(n+1==data){
                now->next=now->next->next;
                return;
            }
            n++;
            now=now->next;
        }
    }
}

Node* createList(){
    int n;
    int count=0;
    scanf("%d", &n);
    Node *temp = (Node*)malloc(sizeof(Node));
    Node *head = (Node*)malloc(sizeof(Node));
    if(n==-1){
        return NULL;
    }
    while(n!=-1){
        if(count == 0){
            head->data=n;
            temp = head;
            count++;
        }
        else{
            Node *new = (Node*)malloc(sizeof(Node));
            new->data = n;
            temp->next = new;
            temp = new;
        }
        scanf("%d", &n);
    }
    return head;
}