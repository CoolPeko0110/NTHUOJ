#include "function.h"
#include <iostream>
#include <string>
using namespace std;
Card* Construct(int n){
    int val;
    Card *head = new Card;
    head->nxt = NULL;
    Card *temp = head;
    while(n--){
        std::cin >> val;
        Card *now = new Card;
        now->num = val;
        now->nxt = NULL;
        temp->nxt = now;
        temp = now;
    }
    return head;
}
void cut(int a, int b, Card* head){
    Card *temp = head, *tmp;
    while(a--){
        temp = temp->nxt;
    }
    tmp = temp;
    while(b--){
        tmp = tmp->nxt;
    }
    Card *tp = temp->nxt;
    temp->nxt = tmp->nxt;
    tmp->nxt = head->nxt;
    head->nxt = tp;

}
void add(int idx, int num, Card* head){
    Card *temp = head, *now = new Card;
    now->num = num;
    for(int i=0;i<idx;i++){
        temp = temp->nxt;
    }
    now->nxt = temp->nxt;
    temp->nxt = now;
}
void print(Card* head){
    Card *now = head->nxt;
    while(now){
        std::cout << now->num << endl;
        now = now->nxt;
    }
}