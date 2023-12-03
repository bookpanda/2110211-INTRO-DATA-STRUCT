#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"
#include<queue>

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  // Your code here
  // Return something
  for(int i=0;i<mSize;i++) {
    // int parent = (i-1)/2;
    // if(parent < 0) continue;
    // if(mLess(mData[parent],mData[i])) return false;
    int c = (i*2)+1;
    if(c<mSize && mLess(mData[i],mData[c])) return false;
    if(c+1<mSize && mLess(mData[i],mData[c+1])) return false;
  }
  return true;
}

#endif