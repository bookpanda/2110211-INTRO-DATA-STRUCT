#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
  iterator it=a;
  while(it!=b) {
    if(*it == value) {
      iterator tmp(it.ptr);
      tmp++;
      node* n = it.ptr;
      n->prev->next = n->next;
      n->next->prev = n->prev;

      output.mHeader->next->prev = n;
      n->next = output.mHeader->next;

      n->prev = output.mHeader;
      output.mHeader->next = n;

      mSize--;
      output.mSize++;
      it = tmp;
    } else {
      it++;
    }
  }
}

#endif
