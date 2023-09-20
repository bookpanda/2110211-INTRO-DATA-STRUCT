#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  //
  for(int i=0;i<k;i++) {
    res.push_back(this->mData[(i+this->mFront)%this->mCap]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
  int size = to-from;
  this->mData = new T[size]();
  this->mCap = size;
  this->mSize = size;
  int i = 0;
  for(auto it=from;it!=to;it++) {
    // std::cout << "add " << *it << "\n";
    this->mData[i] = *it;
    i++;
  }
  this->mFront = 0;
}

#endif
