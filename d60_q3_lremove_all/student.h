#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  //write your code here
  iterator it = begin();
  while(it!=end()) {
    if(*it == value) {
      node* n = it.ptr;
      iterator tmp(it.ptr->next);
      n->next->prev = n->prev;
      n->prev->next = n->next;
      delete it.ptr;
      it.ptr = tmp.ptr;
      mSize--;
    } else {
      it++;
    }
  }
 }

#endif
