#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
  auto it = std::upper_bound(aux.begin(), aux.end(), idx);
  int i = it - aux.begin();
  int prev = i > 0 ? aux[i-1] : 0;
  return mData[i][idx - prev];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
  aux.push_back(mCap);
}

#endif
