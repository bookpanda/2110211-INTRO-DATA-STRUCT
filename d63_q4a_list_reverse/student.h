#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  if(a==b || mSize==0) return;
  auto bef = a-1;
  if(bef >= begin()) {
    bef->next = b-1;
  }
  a->next = b;
  a->prev = a+1;
  for(auto it=a+1;it<b-1;it++) {
    it->next = (it-1);
    it->prev = (it+1);
  }
  (b-1)->next = (b-2);
  (b-1)->prev = a;
  if(b < end()) {
    b->prev = a;
  }
}

#endif
