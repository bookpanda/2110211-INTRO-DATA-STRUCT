#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a,int b) {
  //your code here
  int t = (b-a+1)/2;
  for(int i=0;i<t;i++) {
    int st = (mFront+a+i) % mCap;
    int ed = (mFront+b-i+mCap) % mCap;
    std::swap(mData[st], mData[ed]);
  }
}

#endif
