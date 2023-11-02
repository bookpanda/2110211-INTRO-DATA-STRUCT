#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include<bits/stdc++.h>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  std::vector<std::pair<int, int>> tmp(ranges.size());
  for(int i=0;i<ranges.size();i++) {
    tmp[i] = {ranges[i].first - begin(), ranges[i].second - begin()};
  }
  sort(tmp.begin(), tmp.end());
  bool del[500010];
  for(int i=0;i<500010;i++) del[i] = false;

  int prev = -1;
  size_t newSize = mSize;
  for(auto x: tmp) {
    // std::cout << x.first << ",  " << x.second << "\n";
    if(x.first < prev) {
      x.first = prev;
    }
    for(int i=x.first; i<x.second;i++) {
      del[i] = true;
      // std::cout << "del " << i << "\n";
      newSize--;
    }
    prev = std::max(prev,x.second);
  }

  int idx=0;
  T* newData = new T[newSize]();
  for(int i=0;i<mSize;i++) {
    if(!del[i]) {
      newData[idx] = mData[i];
      idx++;
    }
  }
  // delete [] mData;
  using std::swap;
  std::swap(mSize, newSize);
  std::swap(mCap, newSize);
  std::swap(mData, newData);

}

#endif
