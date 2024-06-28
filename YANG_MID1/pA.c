#include "function.h"
#include <stdio.h>
#include <stdlib.h>

void eFormSort(Node *head){
    Node *temp = head;
    int idx = 1;
    while(temp){
        Node *tmp = temp;
        while(tmp){
            if(tmp->serial == idx){
                idx++;
            }
            if(tmp->next&&tmp->next->serial == idx){
                Node *tp = tmp->next;
                tmp->next = tp->next;
                tp->next = temp->next;
                temp->next = tp;
                idx++;
                break;
            }
            tmp = tmp->next;
        }
        temp = temp->next;
    }
    temp = head;
}
