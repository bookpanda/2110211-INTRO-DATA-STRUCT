#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<bits/stdc++.h>

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  CP::stack<T> t1,t2;
  while(m>0 && !s2.empty()) {
    t1.push(s2.top());
    m--;
    s2.pop();
  }

  while(k>0 && !empty()) {
    t2.push(top());
    k--;
    pop();
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
