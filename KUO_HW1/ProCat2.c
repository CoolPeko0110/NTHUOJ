#include <stdio.h>
#include <stdlib.h>

#include<stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

bool hasCycle(ListNode *head){
    ListNode *fast = head, *slow = head;
    int flag=0;
    while(fast->next!=NULL&&(fast!=slow||!flag)){
        flag = 1;
        fast = fast->next;
        slow = slow->next;
        if(fast->next!=NULL) fast = fast->next;
    }
    if(fast->next==NULL) return false;
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
