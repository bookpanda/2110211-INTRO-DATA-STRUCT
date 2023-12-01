#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<bits/stdc++.h>
using namespace std;

template <typename T>
std::vector<std::vector<T> > CP::stack<T>::distribute(size_t k) const {
  //write your code here
  int sz = mSize/k;
  int quota = mSize - sz*k;
  int idx=mSize-1;
  std::vector<std::vector<T> > ans;
  for(int i=0;i<k;i++) {
    ans.push_back({});
    int vz = sz;
    if(quota) {
      quota--;
      vz++;
    }
    for(int j=0;j<vz;j++) {
      ans.back().push_back(mData[idx--]);
    }
  }
  return ans;
}
#endif
