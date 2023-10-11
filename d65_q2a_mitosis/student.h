#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{   
    int sz = mSize + (b-a+1);
    if(sz > mCap)
        expand(sz);
    int id1 = mSize-1-b;
    int id2 = mSize-1-a;
    mSize = sz;
    for(int i=mSize-1;i>=id2+b-a+2;i--) {
        mData[i] = mData[i-(b-a+1)];
    }
    int j=id2+(b-a+1);
    for(int i=id2;i>=id1;i--) {
        mData[j] = mData[i];
        j--;
        mData[j] = mData[i];
        j--;
    }
}

#endif