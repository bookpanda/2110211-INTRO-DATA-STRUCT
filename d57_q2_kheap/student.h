#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    T tmp = mData[idx];
    while(idx > 0) {
        size_t p = (idx-1)/4;
        if(mLess(tmp, mData[p])) break;
        mData[idx] = mData[p];
        idx = p;
    }
    mData[idx] = tmp;

}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T tmp = mData[idx];
    size_t c;
    while((c = 4*idx + 1) < mSize) {
        size_t d = c;
        if(d+1 < mSize && mLess(mData[c], mData[d+1]) ) c = d+1;
        if(d+2 < mSize && mLess(mData[c], mData[d+2]) ) c = d+2;
        if(d+3 < mSize && mLess(mData[c], mData[d+3]) ) c = d+3;
        if(mLess(mData[c], tmp)) break;
        mData[idx] = mData[c];
        idx = c;
    }
    mData[idx] = tmp;
}

#endif

