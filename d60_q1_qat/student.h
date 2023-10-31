#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  //
  // you need to return something
  if(idx < 0) idx = (idx+mSize)%mSize;
  return mData[(mFront+idx)%mCap];
}

#endif
