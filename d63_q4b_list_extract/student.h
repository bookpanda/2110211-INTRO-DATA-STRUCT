#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
  if(a==b) return;
  iterator it=a;
  while(it!=b) {
    if(*it == value) {
      node* n = it.ptr;
      it++;
      n->prev->next = n->next;
      n->next->prev = n->prev;
      
      n->prev = output.mHeader;
      n->next = output.mHeader->next;
      mSize--;

      output.mHeader->next->prev = n;
      output.mHeader->next = n;
      output.mSize++;
    } else {
      it++;
    }
  }
}

#endif
