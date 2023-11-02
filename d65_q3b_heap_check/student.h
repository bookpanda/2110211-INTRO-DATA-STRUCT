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
    int a = q.front();
    int c1 = a*2 + 1;
    int c2 = a*2 + 2;
    if(c1<mSize && mLess(mData[a], mData[c1])) return false;
    if(c2<mSize && mLess(mData[a], mData[c2])) return false;
    if(c1 < mSize) q.push(c1);
    if(c2 < mSize) q.push(c2);
    q.pop();
  }
  
  return true;
}

#endif