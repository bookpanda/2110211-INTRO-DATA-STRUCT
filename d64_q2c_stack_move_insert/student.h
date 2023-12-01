#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<bits/stdc++.h>

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  CP::stack<T> t1, t2;

  for(int i=0;i<m;i++) {
    t1.push(s2.top());
    s2.pop();
    if(s2.empty()) break;
  }
  for(int i=0;i<k;i++) {
    t2.push(top());
    pop();
    if(empty()) break;
  }
  while(!t1.empty()) {
    push(t1.top());
    t1.pop();
  }
  while(!t2.empty()) {
    push(t2.top());
    t2.pop();
  }

}
#endif
