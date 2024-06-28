#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node *next, *prev;
}Node;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        Node *head=(Node*)malloc(sizeof(Node));
        head->val=0;
        head->next=NULL;
        head->prev=NULL;
        int n;
        scanf("%d", &n);
        Node *temp=head;
        for(int i=1;i<=n;i++){
            char c;
            scanf(" %c", &c);
            Node *new=(Node*)malloc(sizeof(Node));
            new->val=i;
            if(c=='L'){
                new->next=temp;
                new->prev=temp->prev;
                if(temp->prev) temp->prev->next=new;
                temp->prev=new;
                if(temp==head) head=new;
            }
            else if(c=='R'){
                new->next=temp->next;
                if(temp->next) temp->next->prev=new;
                new->prev=temp;
                temp->next=new;
            }
            temp=new;
        }
        temp=head;
        while(temp){
            printf("%d ", temp->val);
            Node *tmp=temp;
            temp=temp->next;
            free(tmp);
        }
        printf("\n");
    }
    return 0;
}