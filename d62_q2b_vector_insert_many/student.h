#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<bits/stdc++.h>
using namespace std;


template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T> > data) {
  //write your code here
  sort(data.begin(), data.end());
  int dsize = data.size();
  int idx = 0;
  int idxm=0;
  ensureCapacity(mSize+dsize);
  // CP::vector<T> newData = vector(mSize+dsize);
  T *newData = new T[mCap]();
  // for(auto x: data) {
  //   std::cout << x.first << "," << x.second << " ";
  // } std::cout << "\n";

  for(int i=0;i<mSize+dsize;i++) {
    if(idxm == data[idx].first) {
      newData[i] = data[idx].second;
      // std::cout << "newData[" << i << "] = " << data[idx].second << "\n";
      idx++;
    } else {
      newData[i] = mData[idxm];
      // std::cout << "newData[" << i << "] = " << mData[idxm] << "\n";
      idxm++;
    }
  }
  delete [] mData;
  mData = newData;
  mSize += dsize;
}

#endif
