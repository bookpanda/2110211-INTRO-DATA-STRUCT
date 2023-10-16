#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
   T tmp = mData[idx];
   while(idx > 0) {
    int idx2 = (idx-1)/4;
    if(mLess(tmp, mData[idx2])) break;
    mData[idx] = mData[idx2];
    idx = idx2;
   }
   mData[idx] = tmp;

}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T tmp = mData[idx];
    int idx2 = (idx*4)+1;
    while(idx2 < mSize) {
        int finalidx = idx2;
        if(idx2+1 < mSize && mLess(mData[finalidx], mData[idx2+1])) finalidx = idx2+1;
        if(idx2+2 < mSize && mLess(mData[finalidx], mData[idx2+2])) finalidx = idx2+2;
        if(idx2+3 < mSize && mLess(mData[finalidx], mData[idx2+3])) finalidx = idx2+3;

        if(mLess(mData[finalidx], tmp)) break;
        mData[idx] = mData[finalidx];
        idx = finalidx;
        idx2 = (idx*4)+1;
    }
    mData[idx] = tmp;
}

#endif

