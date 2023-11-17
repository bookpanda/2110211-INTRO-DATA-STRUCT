#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
bool CP::list<T>::check() {
  //your code here
  node* n = mHeader->next;
  for(int i=0;i<mSize;i++) {
    if(n==NULL || n->next==NULL || n->prev==NULL || n->prev->next!=n || n->next->prev!=n) return false;
    n = n->next;
  }

  return n == mHeader;
}


#endif
