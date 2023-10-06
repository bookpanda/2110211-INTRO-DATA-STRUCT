#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  int a = k > mSize ? mSize : k;
  for(int i=0;i<a;i++) {
    res.push_back(mData[(mFront+i) % mCap]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
  int sz = to - from;
  this->mData = new T[sz]();
  this->mCap = sz;
  this->mSize = sz;
  int idx=0;
  for(auto it=from;it!=to;it++,idx++) {
    mData[idx] = *it;
  }
  this->mFront = 0;
}

#endif
