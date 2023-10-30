#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    T tmp = mData[idx];
    int idx2 = (idx-1)/4;
    while(idx > 0) {
        if(mLess(tmp, mData[idx2])) break;
        mData[idx] = mData[idx2];
        idx = idx2;
        idx2 = (idx2-1)/4;
    }
    mData[idx] = tmp;

}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T tmp = mData[idx];
    while((4*idx)+1 < mSize) {
        int cidx = (idx*4)+1;
        int idx2 = cidx;
        if(cidx+1<mSize && mLess(mData[idx2], mData[cidx+1])) idx2 = cidx+1;
        if(cidx+2<mSize && mLess(mData[idx2], mData[cidx+2])) idx2 = cidx+2;
        if(cidx+3<mSize && mLess(mData[idx2], mData[cidx+3])) idx2 = cidx+3;

        if(mLess(mData[idx2], tmp)) break;
        mData[idx] = mData[idx2];
        idx = idx2;
    }
    mData[idx] = tmp;
}

#endif

