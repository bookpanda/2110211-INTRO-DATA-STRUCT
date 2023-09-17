#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if(m>0 && a+m<=end() && b+m<=end() && a>=begin() && b>=begin() && ((a+m-1 < b && a<b) || (b+m-1 < a && b<a))) {
    for(int i=0;i<m;i++) {
      std::swap(*(a+i), *(b+i));
    }
    return true;
  } else {
    return false;
  }
}

#endif
