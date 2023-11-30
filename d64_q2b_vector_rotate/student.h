#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  int st = first - begin();
  int ed = last - begin();
  int sz = last-first;
  // k = k%sz;
  // if(k<0) k = (k+mSize)%mSize;
  CP::vector<T> tmp;
  for(int i=k;i<sz;i++) {
    tmp.push_back(mData[st+i]);
  }
  for(int i=0;i<k;i++) {
    tmp.push_back(mData[st+i]);
  }
  for(int i=0;i<sz;i++) {
    mData[st+i] = tmp[i];
  }
}

#endif
