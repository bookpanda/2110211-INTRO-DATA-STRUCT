#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;

  if(it == end()) return result;

  node* p1 = it.ptr;

  p1->prev->next = mHeader;
  result.mHeader->prev = mHeader->prev;
  mHeader->prev->next = result.mHeader;
  mHeader->prev = p1->prev;

  result.mHeader->next = p1;
  p1->prev = result.mHeader;
  
  int s = mSize - pos;
  mSize -= s;
  result.mSize = s;

  return result;
}

#endif
