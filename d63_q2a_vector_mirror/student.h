#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  ensureCapacity(mSize*2);
  // std::cout << "VCAP " << mCap << "\n";
  for(int i=0;i<mSize;i++) {
    mData[mSize+i] = mData[mSize-i-1];
  }
  mSize*=2;
}

#endif
