#include "13863.h"

template <typename T>
T &linked_list<T>::iterator::operator*()
{
    return n->val;
}

// Forward the itarator by pre-increament
template <typename T>
typename linked_list<T>::iterator linked_list<T>::iterator::operator++()
{
    n = n->next;
    return n;
}
// Merge two sorted linked list internally
template <typename T>
typename linked_list<T>::node *linked_list<T>::merge(node *lhs, node *rhs)
{
    if(!lhs) return rhs;
    else if(!rhs) return lhs;
    if(lhs->val >= rhs->val){
        rhs->next = merge(lhs, rhs->next);
        return rhs;
    }
    else{
        lhs->next = merge(lhs->next, rhs);
        return lhs;
    }   
}

// Don't forget thess lines; otherwise compiler would not generate reference symbols and you'll get a CE.
template class linked_list<int>;
template class linked_list<string>;
