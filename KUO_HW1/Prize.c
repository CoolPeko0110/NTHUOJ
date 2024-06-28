#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *previous;
    int x;
    struct node *next;
}Node;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->x = 1;
    Node *head = temp;
    for(int i=2;i<=n;i++){
        Node *new = (Node*)malloc(sizeof(Node));
        new->x = i;
        new->previous = temp;
        temp->next = new;
        temp = temp->next;
    }
    temp->next = head;
    head->previous = temp;
    for(int i=0;i<m;i++){
        int lucky;
        scanf("%d", &lucky);
        if(lucky%2==1){
            temp = head;
            while(--lucky){
                temp = temp->next;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            head = temp->previous;
            printf("%d\n", temp->x);
            free(temp);
        }
        else{
            temp = head->previous;
            while(--lucky){
                temp = temp->previous;
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            head = temp->previous;
            printf("%d\n", temp->x);
            free(temp);
        }
    }
    return 0;
}