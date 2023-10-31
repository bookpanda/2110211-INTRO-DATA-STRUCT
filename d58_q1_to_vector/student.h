#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  int cou=0;
  for(int i=0;i<mSize;i++) {
    res.push_back(mData[(mFront+i)%mCap]);
    cou++;
    if(cou==k) break;
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
  size_t sz = to - from;
  mData = new T[sz]();
  // std::cout << "A\n";
  mCap = sz;
  mSize = sz;
  int idx=0;
  for (auto it=from;it!=to;it++) {
    mData[idx] = *it;
    // std::cout << mData[idx] << "\n";
    idx++;
  }
  this->mFront = 0;
}

#endif
