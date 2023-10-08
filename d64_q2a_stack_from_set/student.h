#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  CP::stack<T> s;
  int sz = 0;
  for(auto it=first;it!=last;it++) {
    s.push(*it);
    sz++;
  }
  this->mData = new T[sz]();
  this->mCap = sz;
  this->mSize = sz;
  int idx = 0;
  while(!s.empty()) {
    mData[idx] = s.top();
    s.pop();
    idx++;
  }

}

#endif
