#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<bits/stdc++.h>
using namespace std;


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T> > data) {
  //write your code here
  sort(data.begin(), data.end());
  // CP::vector<T> tmp;
  ensureCapacity(mSize+data.size());
  T *tmp = new T[mCap]();
  int di=0;
  int idx=0;
  for(int i=0;i<mCap;i++) {
    if(di<data.size() && data[di].first == idx) {
      tmp[i] = (data[di].second);
      di++;
    } else if(idx<mSize){
      tmp[i] = (mData[idx]);
      idx++;
    }
  }

  // for(auto x : tmp) {
  //   std::cout << x << ", ";
  // } std::cout << "\n";

  mSize += data.size();
  delete [] mData;
  mData = tmp;
  // for(int j=0;j<mSize;j++) {
  //   mData[j] = tmp[j];
  // }
}

#endif
