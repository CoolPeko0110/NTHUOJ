#include "13490.h"

template<typename Iterator>
Iterator k_unique(Iterator begin, Iterator end, int n){
    if(begin == end) return end;
    Iterator cur = begin;
    int count = 0;
    while((++begin) != end){
        if(*begin != *cur){
            *(++cur) = *begin;
            count = 0;
        }
        else if(++count<n){
            *(++cur) = *(begin);
        }
    }
    return ++cur;
}