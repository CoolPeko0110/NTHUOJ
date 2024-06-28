#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}Node;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    Node *head = (Node*)malloc(sizeof(Node));
    head->val = 1;
    head->next = NULL;
    Node *temp = head;
    for(int i=2;i<=n;i++){
        Node *new = (Node*)malloc(sizeof(Node));
        new->val = i;
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
    }
    temp->next = head;
    int num = n;
    while(head->next!=head){
        int step = k%n==0?k%n+n:k%n;
        for(int i=0;i<step-1;i++){
            head = head->next;
        }
        temp = head->next;
        head->next = temp->next;
        printf("%d ", temp->val);
        free(temp);
        head = head->next;
        n--;
    }
    printf("%d ", head->val);
    return 0;
}