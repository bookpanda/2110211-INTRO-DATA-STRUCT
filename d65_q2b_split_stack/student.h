#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  int sz = mSize/k;
  int quota = mSize - sz*k;
  std::vector<std::vector<T> > ans;
  for(int i=0;i<k;i++) {
    int vs = sz;
    if(quota) {
      quota--;
      vs++;
    }
    ans.push_back({});
    CP::stack<T> s;
    for(int j=0;j<vs;j++) {
      s.push(mData[mSize-1-i-j*k]);
    }
    while(!s.empty()) {
      ans.back().push_back(s.top());
      s.pop();
    }
  }
  return ans;
  //should return something
}

#endif

