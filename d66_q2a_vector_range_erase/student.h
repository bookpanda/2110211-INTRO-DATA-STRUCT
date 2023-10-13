#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include<bits/stdc++.h>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  CP::vector<std::pair<int,int> > r, tmp;
  for(auto x: ranges) {
    int id1 = x.first - begin();
    int id2 = x.second - begin();
    r.push_back({id1,id2});
  }
  std::sort(r.begin(), r.end());
  for(auto x: r) {
    if(tmp.size() == 0) {
      tmp.push_back(x);
      continue;
    }
    if(tmp[tmp.size()-1].second >= x.first) {
      tmp[tmp.size()-1].second = std::max(x.second, tmp[tmp.size()-1].second);
    } else {
      tmp.push_back(x);
    }
  }
  bool a[500010];
  for(int i=0;i<500010;i++) a[i] = true;
  CP::vector<T> ans;
  for(auto x: tmp) {
    // std::cout << "[" << x.first << ", " << x.second << ")\n";
    for(int i=x.first;i<x.second;i++) {
      // std::cout << "push_back " << mData[i] << "\n";
      a[i] = false;
    }
  }
  for(int i=0;i<mSize;i++) {
    if(a[i] == true) {
      ans.push_back(mData[i]);
    }
  }
  std::swap(this->mSize, ans.mSize);
  std::swap(this->mCap, ans.mCap);
  std::swap(this->mData, ans.mData);

}

#endif
