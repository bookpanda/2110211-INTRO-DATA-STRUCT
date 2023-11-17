#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for(auto &l:ls) {
    node* n = l.mHeader;

    //last of old
    mHeader->prev->next = n->next;
    n->next->prev = mHeader->prev;

    //mHeader of old
    mHeader->prev = n->prev;
    n->prev->next = mHeader;

    n->prev = n;
    n->next = n;
    mSize+=l.mSize;
    l.mSize=0;
  }
}

#endif
