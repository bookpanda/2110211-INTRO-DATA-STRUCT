#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
    // code here
    std::vector<CP::queue<T> > ans(k);
    for(int i=0;i<mSize;i++) {
        ans[i%k].push(mData[(mFront+i)%mCap]);
    }
    delete [] mData;
    int cap = 1;
    mData = new T[cap]();
    mCap = cap;
    mSize = 0;
    mFront = 0;
    return ans;
}

#endif

