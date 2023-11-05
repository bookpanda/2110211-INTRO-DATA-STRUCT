#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  T ans;
  bool assign = false;
  for(auto x: pos) {
    if(x > mSize-1) continue;
    if(!assign) {
      assign = true;
      ans = mData[(mFront+x)%mCap];
    } else {
      if(comp(mData[(mFront+x)%mCap],ans)) ans = mData[(mFront+x)%mCap];
    }
  }
  return ans;
  //should return something
  
}

#endif
