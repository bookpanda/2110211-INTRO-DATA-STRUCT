#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{   
   int sz = b-a+1;
   if (mSize + sz > mCap) expand(mCap * 2);
   T tmp[sz], tai[a];
   for(int i=0;i<sz;i++) {
    tmp[i] = mData[mSize-1-b+i];
   }
   for(int i=0;i<a;i++) {
    tai[i] = mData[mSize-a+i];
   }
//    for(auto x: tmp) {
//     std::cout << x << "\n";
//    }
//    std::cout << "tai--\n";
//     for(auto x: tai) {
//     std::cout << x << "\n";
//    }
//    std::cout << "taiended\n";
   int idx=0;
   for(int i=0;i<sz;i++) {
    mData[mSize-1-b+idx] = tmp[i];
    idx++;
    mData[mSize-1-b+idx] = tmp[i];
    idx++;
   }
   for(int i=0;i<a;i++) {
    mData[mSize-1-b+idx] = tai[i];
    idx++;
   }
   mSize += sz;

}

#endif