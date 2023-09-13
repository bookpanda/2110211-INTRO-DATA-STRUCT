#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::valid_iterator(CP::vector<T>::iterator it) const {
  //write your code here
  // std::cout << &(*it) << "\n";
  // std::cout << &mData[0] << "\n";
  // std::cout << &mData[mSize-1] << "\n";
  // return &(*it) >= &mData[0] && &(*it) <= &mData[mSize-1];
  return it >= mData && it < mData+mSize;
}

#endif
