#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::queue<T>::operator==(const CP::queue<T> &other) const {
  //write your code here
  int sz1 = this->mSize;
  int sz2 = other.mSize;
  if(sz1 != sz2) return false;
  int mf1 = this->mFront;
  int mc1 = this->mCap;
  int mf2 = other.mFront;
  int mc2 = other.mCap;
  for(int i=0;i<sz1;i++) {
    if(this->mData[(i+mf1)%mc1] !=other.mData[(i+mf2)%mc2])
      return false;
  }
  return true;
}

#endif
