#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  list<T> a;

  if(it==end()) return a;
  
  node* n =  it.ptr;
  n->prev->next = mHeader;
  a.mHeader->prev = mHeader->prev;
  a.mHeader->next = n;
  mHeader->prev->next = a.mHeader;
  mHeader->prev = n->prev;

  n->prev = a.mHeader;
//   n->next = 

  a.mSize = mSize-pos;
  mSize = pos;

  return a;
}

#endif
