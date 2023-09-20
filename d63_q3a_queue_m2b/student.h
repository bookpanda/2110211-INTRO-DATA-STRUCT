#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  int st = (mFront+pos)%mCap;
  int ed = (mFront+mSize-1)%mCap;
  int save = mData[st];
  for(int i=0;i<(mSize-pos-1);i++) {
    // std::cout << "SWAP " << mData[(st+i)%mCap] << " with " << mData[(st+i+1+mCap)%mCap] << "\n";
    // std::swap(mData[(st+i)%mCap], mData[(st+i+1+mCap)%mCap]);
    mData[(st+i)%mCap] = mData[(st+i+1)%mCap];
  }
  mData[ed] = save;
  // push(mData[st]);

}

#endif
