#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for(auto &l:ls) {
    mHeader->prev->next = l.mHeader->next;
    l.mHeader->next->prev = mHeader->prev;
    mHeader->prev = l.mHeader->prev;
    l.mHeader->prev->next = mHeader;

    mSize += l.size();

    l.mHeader->next = l.mHeader;
    l.mHeader->prev = l.mHeader;
    l.mSize = 0;
  }
  // ls.mSize = 0;
}

#endif
