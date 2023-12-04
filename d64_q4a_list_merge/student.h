#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for(CP::list<T> &l: ls) {
    node* n = mHeader;
    n->prev->next = l.mHeader->next; //last of old
    l.mHeader->next->prev = n->prev;

    mHeader->prev = l.mHeader->prev;
    l.mHeader->prev->next = mHeader;

    l.mHeader->next = l.mHeader;
    l.mHeader->prev = l.mHeader;

    mSize += l.mSize;
    l.mSize = 0;
    // delete l.mHeader;
  }
}

#endif
