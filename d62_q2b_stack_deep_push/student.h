#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos,const T& value) {
  //write your code here
  pos = std::min(mSize, pos);
  ensureCapacity(mSize+1);
  int idx = mSize - pos;
  mSize++;
  for(int i=mSize-1;i>idx;i--) {
    mData[i] = mData[i-1];
  }
  mData[idx] = value;
}

#endif
