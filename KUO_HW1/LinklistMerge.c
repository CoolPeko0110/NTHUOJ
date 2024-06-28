#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode {
    int val;
    struct _ListNode* next;
} ListNode;

ListNode* mergeLinkedList(ListNode* lhs, ListNode* rhs){
    ListNode *head = (lhs->val>=rhs->val)?rhs:lhs;
    ListNode *tempL = lhs, *tempR = rhs;
    while(tempL!=NULL&&tempR!=NULL){
        if(tempL->val>tempR->val||(tempL->val==tempR->val&&lhs->val>=rhs->val)){
            ListNode *temp = tempL->next;
            while(tempR->next!=NULL&&tempR->next->val<=tempL->val){
                tempR = tempR->next;
            }
            tempL->next = tempR->next;
            tempR->next = tempL;
            tempR = tempR->next;
            tempL = temp;
        }
        else if(tempL->val<tempR->val||(tempL->val==tempR->val&&lhs->val<rhs->val)){
            ListNode *temp = tempR->next;
            while(tempL->next!=NULL&&tempL->next->val<=tempR->val){
                tempL = tempL->next;
            }
            tempR->next = tempL->next;
            tempL->next = tempR;
            tempL = tempL->next;
            tempR = temp;
        }
    }
    return head;
}


ListNode* readList(int n) {
    ListNode* nodes = malloc(sizeof(ListNode) * (n + 1));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nodes[i].val);
        nodes[i - 1].next = &(nodes[i]);
    }
    nodes[n].next = NULL;
    return nodes;
}

int main() {
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        ListNode* lhs = readList(n);
        ListNode* rhs = readList(m);
        ListNode* merged = mergeLinkedList(lhs[0].next, rhs[0].next);
        for (ListNode* cur = merged; cur; cur = cur->next)
            printf("%d%c", cur->val, " \n"[!cur->next]);
        free(lhs);
        free(rhs);
    }

    return 0;
}
