#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  T min;
  bool isset = false;
  for(int i=0;i<pos.size();i++) {
    if(pos[i] >= mSize) continue;
    int idx = (mFront+pos[i]) % mCap;
    if(!isset) {
      min = mData[idx];
      isset = true;
    }
    if(comp(mData[idx],min)) {
      min = mData[idx];
    }
  }
  //should return something
  return min;
}

#endif
