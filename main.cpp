#include <iostream>
#include "container.h"
int main(){
    //constructors test

    auto alloc = std::allocator<int>(); //default allocator
    container<int> c1;
    container<int> c2(alloc);
    container<int> c3(5, 10);
    container<int> c4(5, 10, alloc);
    container<int> c5(c3);
    container<int> c6(c3, alloc);
    container<int> c7({1,2,3,4,5});
    container<int> c8({1,2,3,4,5}, alloc);
    

}