#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> ans;
  if(it==end()) return ans;
  
  node* n = it.ptr;

  ans.mHeader->prev = mHeader->prev;
  mHeader->prev->next = ans.mHeader;
  //n - mHeader
  n->prev->next = mHeader;
  mHeader->prev = n->prev;
  

  //n - ans
  n->prev = ans.mHeader;
  ans.mHeader->next = n;

  ans.mSize = mSize-pos;
  mSize = pos;
  return ans;
}

#endif
