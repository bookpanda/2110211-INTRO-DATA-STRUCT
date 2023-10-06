#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<bits/stdc++.h>
using namespace std;

template <typename T>
std::vector<std::vector<T> > CP::stack<T>::distribute(size_t k) const {
  //write your code here
  std::vector<std::vector<T> > v;
  int idx=mSize-1;
  int sz = mSize / k;
  int r = mSize - sz*k;
  for(int i=0;i<k;i++) {
    std::vector<T> a;
    for(int j=0;j<sz;j++) {
      if(idx >=0)
        a.push_back(mData[idx]);
      idx--;
    }
    if(r){
      a.push_back(mData[idx]);
      idx--;
      r--;
    }
    // for(auto x: a) {
    //   std::cout << x << " ";
    // } std::cout << "\n";

    v.push_back(a);
  }

  return v;
}
#endif
