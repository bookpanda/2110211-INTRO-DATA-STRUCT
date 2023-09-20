#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  //
  // you need to return something
  int i;
  if(idx>-1) i = (mFront+idx) % mCap;
  else  i = (mFront+mSize+idx) % mCap;

  return mData[i];
}

#endif
