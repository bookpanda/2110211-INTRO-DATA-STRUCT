#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
  //write your code here
  iterator it = begin();
  while(it != end()) {
    // std::cout << "val = " << *it << "\n"; 
    if(*it == value) { 
      iterator tmp(it.ptr->next);

      node* p = it.ptr;
      p->prev->next = p->next;
      p->next->prev = p->prev;
      mSize--;

      delete it.ptr;
      it = tmp;
    } else {
      it++;
    }
  }
}

#endif
