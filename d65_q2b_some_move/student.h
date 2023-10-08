#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  auto it = std::lower_bound(aux.begin(), aux.end(), index);
  int i = it - aux.begin();
  // if(index == 0) {
  //   mData.insert(mData.begin(), value);

  // } else if(index == mSize) {
  //   mData.push_back(value);
  // } else
  if(i < 1800) {//new vector
    int prev = i > 0 ? aux[i-1] : 0;
    int pos = index - prev;
    int sz = mData[i].size();
    int afterpos = sz-pos;
    aux[i] -= afterpos;
    mData.insert(mData.begin() + i+1, value);
    aux.insert(aux.begin() + i+1, aux[i]);
    std::vector<T> temp;
    for(int a=pos;a<mData[i].size();a++) {
      temp.push_back(mData[i][a]);
    }
    mData.insert(mData.begin() + i+2, temp);
    aux.insert(aux.begin() + i+2, aux[i]+afterpos);
    mData[i].erase(mData[i].begin() + pos, mData[i].end());
    i++;
  } else {//current vector
    int prev = i > 0 ? aux[i-1] : 0;
    int pos = index - prev;
    mData[i].insert(mData[i].begin() + pos, value.begin(), value.end());
  }

  while(i<aux.size()) {
    aux[i] += value.size();
    i++;
  }
  mCap+=value.size();
  mSize+=value.size();
}

#endif