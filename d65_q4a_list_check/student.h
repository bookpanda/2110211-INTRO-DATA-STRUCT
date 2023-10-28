#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
bool CP::list<T>::check() {
  //your code here
  if(mHeader == NULL) return false;

  iterator it = begin();

  for(int i=0;i<mSize;i++) {
    if(it.ptr == NULL || it.ptr->prev==NULL || it.ptr->prev->next != it.ptr || it.ptr->next==NULL || it.ptr->next->prev != it.ptr) return false;
    it++;
  }

  return it.ptr == mHeader;
}


#endif
