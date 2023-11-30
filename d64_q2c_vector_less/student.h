#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
  if(mSize == 0 && other.mSize > 0) return true;
  int sz = std::min(mSize, other.mSize);
  for(int i=0;i<sz;i++) {
    if(mData[i] < other.mData[i]) return true;
    else if(mData[i] > other.mData[i]) return false;
  }
  if(mSize < other.mSize) return true;
  // else if(mSize == other.mSize) return fa;

  return false;
}

#endif
