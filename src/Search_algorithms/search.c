#include "search.h"

const int *binary_search(int value, const int *arr, size_t length){
    if (length <=0) { return NULL;}
    
    size_t mid = length / 2;
    if(value ==  arr[mid])
        return arr + mid;
    else
        return value < arr[mid] ? binary_search(value, arr, mid) : binary_search(value, arr+mid+1, length - mid - 1);
}