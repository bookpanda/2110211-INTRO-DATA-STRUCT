#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
     T tmp = mData[idx];
      while (idx > 0) {
        size_t p = (idx - 1) / 4;
        if ( mLess(tmp,mData[p]) ) break;
        mData[idx] = mData[p];
        idx = p;
      }
      mData[idx] = tmp;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T tmp = mData[idx];
    size_t c;
    while ((c = 4 * idx + 1) < mSize) {
      int tid = c+1;
      if (tid < mSize && mLess(mData[c],mData[tid]) ) c = tid;
      if (tid + 1 < mSize && mLess(mData[c],mData[tid + 1]) ) c = tid+1;
      if (tid + 2 < mSize && mLess(mData[c],mData[tid + 2]) ) c = tid+2;
      if ( mLess(mData[c],tmp) ) break;
      mData[idx] = mData[c];
      idx = c;
    }
    mData[idx] = tmp;
}

#endif

