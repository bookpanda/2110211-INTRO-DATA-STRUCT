#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
bool CP::list<T>::check() {
  //your code here
  if(mHeader == NULL) return false;
  iterator it = begin();
  for(int i=0;i<mSize;i++) {
    node* n = it.ptr;
    if(n==NULL || n->prev==NULL || n->next==NULL || n->prev->next!=n || n->next->prev!= n) return false;
    it++;
  }
 
 return it.ptr==mHeader;
}


#endif
