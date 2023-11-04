#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<bits/stdc++.h>
using namespace std;

template <typename T>
std::vector<std::vector<T> > CP::stack<T>::distribute(size_t k) const {
  //write your code here
  int sz = mSize/k;
  int quota = mSize - sz*k;
  int idx = mSize-1;
  std::vector<std::vector<T> > ans;
  for(int i=0;i<k;i++) {
    ans.push_back({});
    int vs = sz;
    if(quota) {
      quota--;
      vs++;
    }
    for(int j=0;j<vs;j++) {
      // cout << "push " << mData[idx] << "\n";
      ans.back().push_back(mData[idx]);
      idx--;
    }
  }
  return ans;
}
#endif
