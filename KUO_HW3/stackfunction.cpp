#include"stackfunction.h"
#include<iostream>

List_stack::List_stack(){
    head = tail = nullptr;
}
List_stack::~List_stack(){

}
void List_stack::push(const int &num){
    ListNode *now = new ListNode(num);
    if(!head){
        head = tail = now;
    }
    else{
        now->prevPtr = tail;
        tail->nextPtr = now;
        tail = now;
    }
}
void List_stack::pop(){
    if(!head) return;
    if(!tail->prevPtr){
        delete tail;
        head = tail = nullptr;
        return;
    }
    tail->prevPtr->nextPtr = nullptr;
    ListNode *temp = tail;
    tail = tail->prevPtr;
    delete temp;
}
void List_stack::print(){
    ListNode *cur = tail;
    while(cur){
        std::cout<<cur->data;
        if(cur!=head) std::cout<<" "; 
        cur = cur->prevPtr;
    }
}