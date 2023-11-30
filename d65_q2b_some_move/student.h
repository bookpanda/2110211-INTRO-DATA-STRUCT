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
  int aid = it - aux.begin();
  int bef = aid>0 ? aux[aid-1] : 0;

  if(mData[aid].size() > 2000) { //new vector, remove chunk, add value, add chunk
    std::vector<T> tmp;
    int st = index-bef;
    for(int i=st;i<mData[aid].size();i++) {
      tmp.push_back(mData[aid][i]);
    }
    mData.insert(mData.begin()+aid+1, tmp);
    aux.insert(aux.begin()+aid+1, aux[aid]);

    aux[aid] -= mData[aid].size() - st;
    mData[aid].erase(mData[aid].begin()+st, mData[aid].end());

    mData.insert(mData.begin()+aid+1, value);
    aux.insert(aux.begin()+aid+1, aux[aid]);


    // aid++;
  } else { //old vector, insert value
    int a = index-bef;
    mData[aid].insert(mData[aid].begin()+a, value.begin(), value.end());
    aux[aid] += value.size();
  }

  for(int i=aid+1;i<aux.size();i++) {
    aux[i] += value.size();
  }

  mSize += value.size();
  mCap += value.size();
}

#endif