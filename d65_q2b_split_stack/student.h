#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  std::vector<std::vector<T> > ans(k);
  int st = mSize-1; 
  int sz = mSize/k;
  int idx = 0;
  int quota = mSize - sz*k;
  for(int i=0;i<k;i++) {
    int vsize = sz;
    if(quota) {
      quota--;
      vsize++;
    }

    CP:stack<T> s;
    for(int j=0;j<vsize;j++) {
      s.push(mData[st - (j*k)]);
    }
    while(!s.empty()) {
      ans[idx].push_back(s.top());
      s.pop();
    }

    idx++;
    st--;
  }
  return ans;
  //should return something
}

#endif

