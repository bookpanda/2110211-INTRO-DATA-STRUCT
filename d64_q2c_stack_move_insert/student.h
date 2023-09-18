#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<bits/stdc++.h>

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  std::stack<T> s;
  std::stack<T> q;
  int cou = 0;
  while(cou<m && !s2.empty()) {
    q.push(s2.top());
    s2.pop();
    cou++;
    if(cou == m) break;
  }

  cou = 0;
  while(cou<k && !this->empty()) {
    s.push(this->top());
    this->pop();
    cou++;
    if(cou == k) break;
  }

  while(!q.empty()) {
    this->push(q.top());
    q.pop();
  }
  while(!s.empty()) {
    this->push(s.top());
    s.pop();
  }


}
#endif
