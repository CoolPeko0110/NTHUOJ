#include "13131function.h"

Array_MAX_HEAP::Array_MAX_HEAP(){
    array[0] = 0;
}
void Array_MAX_HEAP::PUSH(const int &x){
    array[++Count] = x;
    int count = Count;
    while(count>1){
        if(array[count]>array[count/2]){
            count /= 2;
        }
        else break;
    }
}
int Array_MAX_HEAP::MAX() const{
    if(!Count) return -1;
    else return array[1];
}
int Array_MAX_HEAP::POP(){
    if(!Count){
        return -1;
    }
    else if(Count == 1){
        --Count;
        return array[1];
    }
    else{
        int retval = array[1];
        array[1] = array[Count--];
        int count = 1;
        while(count<=Count/2){
            int left = count*2, right = count*2+1;
            if(array[count]<array[left]||array[count]<array[right]){
                if(right<=Count){
                    int pos = array[left]>array[right]?left:right;
                    std::swap(array[count], array[pos]);
                    count = pos;
                }
                else{
                    std::swap(array[left], array[count]);
                    count = left;
                }
            }
            else break;
        }
        return retval;
    }
}

List_MAX_HEAP::List_MAX_HEAP(){
    root = NULL;
    Count = 0;
}
void List_MAX_HEAP::PUSH(const int &x){
    ListNode *now = new ListNode(x);
    ++Count;
    if(Count == 1){
        root = now;
        return;
    }
    ListNode *father = findparent(Count, this->root);
    if(father->left) father->right = now;
    else father->left = now;
}
int List_MAX_HEAP::MAX() const{
    if(!Count) return -1;
    else return root->value;
}
int List_MAX_HEAP::POP(){
    if(!Count) return -1;
    else if(Count == 1){
        int retval = root->value;
        ListNode *father = findparent(Count, this->root);
        if(!Count%2){
            root->value = father->left->value;
            delete father->left;
            father->left = NULL;
            --Count;
        }
        else{
            root->value = father->right->value;
            delete father->right;
            father->right = NULL;
            --Count;
        }
        ListNode *temp = root;
        return retval;
    }
}
void List_MAX_HEAP::deleteTree(ListNode *root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}