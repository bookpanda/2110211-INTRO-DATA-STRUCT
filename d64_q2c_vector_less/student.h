#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
  int sa = size();
  int sb = other.size();
  if(sa == 0 && sb == 0) return false;
  if(sa == 0 && sb>0) return true;
  if(sa > 0 && sb == 0) return false;
  
  if(sa > 0 && sb > 0 && mData[0] < other[0]) return true;
  // if(sa > 0 && sb > 0 && mData[0] == other[0])
  int ms = std::min(sa, sb);
  for(int i=0;i<ms;i++) {
    if(mData[i] < other[i]) return true;
    else if(mData[i] == other[i]) continue;
    else return false;
  }
  return sa < sb;
}

#endif
