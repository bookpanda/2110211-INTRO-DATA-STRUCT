#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  std::vector<std::vector<T> > v;
  int sz = mSize / k;
  for(int i=1;i<=k;i++) {
    std::vector<T> v1;
    CP::stack<T> s;
    for(int j=0;j<=sz;j++) {
      int idx = mSize-(i + j*k);
      if(idx >= 0) {
        s.push(mData[idx]);
      }
    }
    while(!s.empty()) {
      v1.push_back(s.top());
      s.pop();
    }
    v.push_back(v1);
  }

  return v;
  //should return something
}

#endif

