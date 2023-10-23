#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
  if(mSize==0) return;
  auto it = a;
  while(it != b) {
    if(*it == value) {
      iterator tmp(it.ptr->next);
      node *p = new node(it.ptr->data, output.mHeader, output.mHeader->next);
      output.mHeader->next = p;
      output.mHeader->next->prev = p;
      // p->next->prev = p;
      // p->prev->next = pt;
      output.mSize++;

      it.ptr->next->prev = it.ptr->prev;
      it.ptr->prev->next = it.ptr->next;
      mSize--;

      delete it.ptr;
      it = tmp;
    } else {
      it++;
    }
  }
}

#endif
