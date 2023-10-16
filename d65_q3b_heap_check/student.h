#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"
#include<queue>

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  // Your code here
  // Return something
  std::queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int i = q.front();
    if((2*i+1 < mSize && mLess(mData[i], mData[2*i+1])) || (2*i+2 < mSize && mLess(mData[i], mData[2*i+2]))) return false;
    if(2*i+1 < mSize)
      q.push(2*i+1);
    if(2*i+2 < mSize)
      q.push(2*i+2);
    q.pop();
  }

  return true;
}

#endif