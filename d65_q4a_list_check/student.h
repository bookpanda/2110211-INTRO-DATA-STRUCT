#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
bool CP::list<T>::check() {
  //your code here
  iterator it = begin();
  for(int i=0;i<mSize;i++) {
    node* n = it.ptr;
    if(!n || !n->prev || !n->next || n->prev->next != n || n->next->prev != n) return false;
    it++;
  }
  return it.ptr == mHeader;
}


#endif
