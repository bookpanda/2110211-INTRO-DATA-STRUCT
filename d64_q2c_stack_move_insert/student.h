#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<bits/stdc++.h>

template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  CP::stack<T> tmp, tmp2;
  int cou=0;
  while(cou<m && !s2.empty()) {
    tmp.push(s2.top());
    s2.pop();
    cou++;
  }
  cou=0;
  while(cou < k && !empty()) {
    tmp2.push(top());
    pop();
    cou++;
  }
  while(!tmp.empty()){
    push(tmp.top());
    tmp.pop();
  }
  while(!tmp2.empty()){
    push(tmp2.top());
    tmp2.pop();
  }


}
#endif
