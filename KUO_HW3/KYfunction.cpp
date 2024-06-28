#include "KYfunction.h"
#include <iostream>
#include <math.h>
KuoYangPresent::KuoYangPresent(int k) {
	this->head = this->tail = this->mid = nullptr;
    this->k = k;
    this->sz = 0;
    this->reverse = 0;
}
void KuoYangPresent::Push(int x) {
    sz++;
	if(!tail){
        Node *cur = new Node;
        cur->val = x;
        cur->tag = 1;
        cur->next = nullptr;
        cur->prev = nullptr;
        head = tail = cur;
    }
    else{
        Node *cur = new Node;
        cur->val = x;
        cur->tag = sz;
        if(!reverse){
            cur->next = nullptr;
            cur->prev = tail;
            tail->next = cur;
            tail = cur;
        }
        else{
            cur->prev = nullptr;
            cur->next = tail;
            tail->prev = cur;
            tail = cur;
        }
    }
    if(mid){
        if(!reverse){
            if(abs(mid->tag) != (sz+1)/2){
                mid = mid->next;
                mid->tag = (mid->tag<0)?-(sz+1)/2:(sz+1)/2;
            }
        }
        else{
            if(abs(mid->tag) != (sz+1)/2){
                mid = mid->prev;
                mid->tag = (mid->tag<0)?-(sz+1)/2:(sz+1)/2;
            }
        }
    }
}
void KuoYangPresent::Pop() {
    if(!tail) return;
	if(sz){
        if(mid == nullptr){
            Node *temp = head;
            for(int i=1;i<(sz+1)/2;i++){
                if(!reverse) temp = temp->next;
                else temp = temp->prev;
            }
            if(temp == head) head = mid = tail = nullptr;
            else{
                if(temp->prev){
                    temp->prev->next = temp->next;
                }
                if(temp->next){
                    temp->next->prev = temp->prev;
                }
                sz--;
                if(abs(temp->tag) == (sz+1)/2){
                    if(!reverse) mid = temp->next;
                    else mid = temp->prev;
                    mid->tag = (mid->tag<0)?-((sz+1)/2):((sz+1)/2);
                }
                else{
                    if(!reverse) mid = temp->prev;
                    else mid = temp->next;
                    mid->tag = (mid->tag<0)?-((sz+1)/2):((sz+1)/2);
                }
                delete temp;
            }
        }
        else{
            if(mid == tail){
                head = mid = tail = nullptr;
                return;
            }
            if(mid == head){
                if(!reverse){
                    mid = head->next;
                    mid->prev = nullptr;
                }
                else{
                    mid = head->prev;
                    mid->next = nullptr;
                }
                mid->tag = (mid->tag<0)?-((sz+1)/2):((sz+1)/2);
                Node *temp = head;
                head = mid;
                delete temp;
                return;
            }
            Node *temp = mid;
            if(temp->prev){
                temp->prev->next = temp->next;
            }
            if(temp->next){
                temp->next->prev = temp->prev;
            }
            sz--;
            if(temp->tag == (sz+1)/2){
                if(!reverse) mid = temp->next;
                else mid = temp->prev;
                mid->tag = mid->tag<0?-((sz+1)/2):((sz+1)/2);
            }
            else{
                if(!reverse) mid = temp->prev;
                else mid = temp->next;
                mid->tag = mid->tag<0?-((sz+1)/2):((sz+1)/2);
            }
            delete temp;
        }
    }
}
void KuoYangPresent::Reverse() {
    if(mid&&sz%2 == 0){
        if(!reverse){
            mid->next->tag = mid->next->tag<0?-abs(mid->tag):abs(mid->tag);
            mid = mid->next;
        }
        else{
            mid->prev->tag = mid->prev->tag<0?-abs(mid->tag):abs(mid->tag);
            mid = mid->prev;
        }
    }
    reverse = reverse?0:1;
    Node *tmp = tail;
    tail = head;
    head = tmp;
}
void KuoYangPresent::ProgrammingTanoshi() {
	tail->tag = (tail->tag<0)?(tail->tag):-(tail->tag);
    head->tag = (head->tag<0)?(head->tag):-(head->tag);
}
void KuoYangPresent::KuoYangTeTe() {
    Node *p1 = head, *p2 = tail;
    while(p2){
        if(p2->tag<0) break;
        if(!reverse) p2 = p2->prev;
        else p2 = p2->next;
    }
    while(p1){
        if(p1->tag<0) break;
        if(!reverse) p1 = p1->next;
        else p1 = p1->prev;
    }
    if(p1&&p2){
        if(!reverse){
            while(p1!=p2){
                p1->val %= k;
                p1 = p1->next;
            }
            p2->val %= k;
        }
        else{
            while(p1!=p2){
                p1->val %= k;
                p1 = p1->prev;
            }
            p2->val %= k;
        }
    }
}
void KuoYangPresent::PrintList() {
    Node *temp = head;
    while(temp){
        std::cout<<temp->val<<" ";
        if(!reverse) temp = temp->next;
        else temp = temp->prev;
    }
    std::cout<<"\n";
}