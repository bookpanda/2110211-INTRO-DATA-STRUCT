#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    // expand(mSize + (b-a+1));
    T *newData = new T[mSize+(b-a+1)];

    for(int i=0;i<mSize-b-1;i++) {
        newData[i] = mData[i];
    }
    // for(int j=0;j<mSize+(b-a+1);j++) {
    //     std::cout << newData[j] << " " ;
    // } std::cout << "\n";
    int idx = mSize-b-1;
    for(int i=mSize-b-1;i<mSize-a;i++) {
        newData[idx] = mData[i];
        idx++;
        newData[idx] = mData[i];
        idx++;
        // for(int j=0;j<mSize+(b-a+1);j++) {
        //     std::cout << newData[j] << " " ;
        // } std::cout << "\n";
    }

    for(int i=mSize-a;i<mSize;i++) {
        newData[idx] = mData[i];
        idx++;
        // for(int j=0;j<mSize+(b-a+1);j++) {
        //     std::cout << newData[j] << " " ;
        // } std::cout << "\n";
    }

    delete [] mData;
    mData = newData;
    mSize += b-a+1;
    mCap += b-a+1;
}

#endif