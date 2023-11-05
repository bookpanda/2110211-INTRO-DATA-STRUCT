#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"
#include<queue>

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  // Your code here
  // Return something
  for(int i=0;i<mSize;i++) {
    int ca = i*2 + 1;
    int cb = i*2 + 2;
    if(ca < mSize && mLess(mData[i], mData[ca])) return false;
    if(cb < mSize && mLess(mData[i], mData[cb])) return false;
  }
  return true;
}

#endif