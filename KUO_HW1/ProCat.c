#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

bool hasCycle(ListNode *head){
    #include<stdlib.h>
    ListNode *temp = head;
    int count=0;
    while(head->next!=NULL&&head->val<=1000000000&&head->val>=-1000000000){
        if(head->val>=0) head->val+=1000000010;
        else head->val-=1000000010;
        head=head->next;
        count++;
    }
    for(int i=0;i<count;i++){
        if(temp->val>=1000000010) temp->val-=1000000010;
        else temp->val+=1000000010;
        temp = temp->next;
    }
    if(head->next==NULL){
        return false;
    }
    else return true;
}

int solve() {
    int n;
    scanf("%d", &n);
    int* c = (int*)malloc(n * sizeof(int));
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    ListNode** nodes = (ListNode**)malloc(n * sizeof(ListNode*));
    for (int i = 0; i < n; ++i) nodes[i] = (ListNode*)malloc(sizeof(ListNode));
    for (int i = 0; i < n; ++i) {
        nodes[i]->next = (c[i] == -1 ? NULL : nodes[c[i]]);
        nodes[i]->val = a[i];
    }

    int res = (hasCycle(nodes[0]) ? 1 : 0);

    for (int i = 0; i < n; ++i) {
        if (!nodes ||
            nodes[i]->next != (c[i] == -1 ? NULL : nodes[c[i]]) ||
            nodes[i]->val != a[i]) {
            res = -1;
            break;
        }
    }

    for (int i = 0; i < n; ++i) free(nodes[i]);
    free(nodes);
    free(a);
    free(c);

    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int res = solve();
        if (res == -1)
            printf("You should not modify the given linked list\n");
        else if (res == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
