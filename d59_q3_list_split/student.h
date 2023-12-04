#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> ans;
  if(it==end()) return ans;
  
  node* n = it.ptr;

  n->prev->next = mHeader;

  ans.mHeader->next = n;

  ans.mHeader->prev = mHeader->prev;
  mHeader->prev->next = ans.mHeader;

  mHeader->prev = n->prev;
  n->prev = ans.mHeader;

  ans.mSize = mSize-pos;
  mSize = pos;

  return ans;
}

#endif
