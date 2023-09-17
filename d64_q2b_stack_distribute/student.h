#ifndef __STUDENT_H__
#define __STUDENT_H__
#include<bits/stdc++.h>
using namespace std;

template <typename T>
std::vector<std::vector<T> > CP::stack<T>::distribute(size_t k) const {
  //write your code here
  vector<vector<T> > v;
  int sizeperv = mSize/k;
  int rtil = mSize - k*sizeperv;

  int vidx=0;
  vector<T> a;
  v.push_back(a);
  for(int i=mSize-1;i>=0;i--) {
    v[vidx].push_back(mData[i]);
    if(vidx < rtil) {
      if(v[vidx].size() == sizeperv+1) {
        vidx++;
        vector<T> a;
        v.push_back(a);
      } 
    } else {
      if(v[vidx].size() == sizeperv) {
        vidx++;
        vector<T> a;
        v.push_back(a);
      } 
    }
  }

  return v;
}
#endif
