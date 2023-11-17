#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
  if(a==b) return;
  iterator it = a;
  while(it!=b) {
    if(*it == value) {
      node* n = it.ptr;
      it++;
      // iterator tmp(it.ptr->next);

      //old list
      n->prev->next = n->next;
      n->next->prev = n->prev;
      //new list
      //mHeader->next
      output.mHeader->next->prev = n;
      n->next = output.mHeader->next;
      //mHeader
      output.mHeader->next = n;
      n->prev = output.mHeader;

      output.mSize++;
      mSize--;
      
      // it.ptr = tmp.ptr;
    } else {
      it++;
    }
  }
}

#endif
