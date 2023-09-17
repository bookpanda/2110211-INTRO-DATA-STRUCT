#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  // int size = 3;
  // std::cout << "i pos " << *position << "\n";

  int st = position - begin();
  int size = last - first;
  ensureCapacity(mSize+size); //note this
  // std::cout << st << " " << mSize << " " << size << "\n";
  for(int i=mSize+size-1;i>=st+size;i--) {
    mData[i] = mData[i-size];
  }
  // for(auto it=position;it!=end();it++) {
  //   *(it+size) = *it;
  // }
  for(int i=0;i<mCap;i++) {
    std::cout << mData[i] << " ";
  } std::cout << "\n";

  int idx = st;
  for(auto it=first;it!=last;it++) {
    mData[idx] = *it;
    idx++;
  }

  mSize += size;
}

#endif
