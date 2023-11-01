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
  for(auto x: pos) {
    if(x >= mSize) continue;
    // std::cout << min << " " << mData[(mFront+x)%mCap] << "\n";
    if(isset) {
      if(comp(mData[(mFront+x)%mCap], min)) min = mData[(mFront+x)%mCap];
    }
    else {
      min = mData[(mFront+x)%mCap];
      isset = true;
    }
  }
  //should return something
  return min;
}

#endif
