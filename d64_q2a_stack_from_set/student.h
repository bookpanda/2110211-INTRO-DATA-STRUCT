#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  CP::stack<T> s;  
  for(auto it=first;it!=last;it++) {
    s.push(*it);
  }
  this->mData = new T[s.size()]();
  this->mCap = s.size();
  this->mSize = s.size();
  int idx=0;
  while(!s.empty()) {
    mData[idx] = s.top();
    idx++;
    s.pop();
  }
}

#endif
