#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include<bits/stdc++.h>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  std::vector<std::pair<int,int > > v;
  for(int i=0;i<ranges.size();i++) {
    int st = ranges[i].first - begin();
    int ed = ranges[i].second - begin();
    v.push_back({st, ed});
  }
  sort(v.begin(), v.end());
  std::vector<std::pair<int,int > > dr;
  for(int i=0;i<v.size();i++) {
    if(dr.size() == 0)
      dr.push_back({v[i].first, v[i].second});
    else if(dr.back().second >= v[i].first) {
      dr.back().second = std::max(dr.back().second, v[i].second);
    } else {
      dr.push_back({v[i].first, v[i].second});
    }
  }
  // for(auto x: dr) {
  //   std::cout << x.first << " , " << x.second << "\n";
  // }
  std::vector<bool> de(mSize);
  // for(int i=0;i<mSize;i++) de[i] = false;

  for(int i=0;i<dr.size();i++) {
    for(int j=dr[i].first; j<dr[i].second; j++) {
      de[j] = true;
    }
  }

  int idx=0;
  int offset=0;
  for(int i=0;i<mSize;i++) {
    if(!de[i]) {
      mData[idx] = mData[i];
      idx++;
    } else {
      // std::cout << "delete " << mData[i] << "\n";
      offset++;
    }
  }
  mSize-=offset;
}

#endif
