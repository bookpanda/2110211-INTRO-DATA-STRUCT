#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  auto it = lower_bound(aux.begin(), aux.end(), index); //will be in the right vector
  int id = it - aux.begin();
  if(index == 0) {
    mData.insert(mData.begin(), value);
    aux.insert(aux.begin(), value.size());
    id++;
  } else if(index == mSize) {//id = mSize-1
    mData.push_back(value);
    aux.push_back(aux.back());
    id++;
  } else if(mData[id].size() < 1800) { //use same vector
    int pos = id==0 ? index : index - aux[id-1];
    mData[id].insert(mData[id].begin()+pos, value.begin(), value.end());
  } else { //new vector
    int pos = id==0 ? index : index - aux[id-1];
    std::vector<T> temp;
    for(int i=pos;i<mData[id].size();i++) {
      temp.push_back(mData[id][i]);
    }
    mData[id].erase(mData[id].begin()+pos, mData[id].end());
    mData.insert(mData.begin()+id+1, value);
    mData.insert(mData.begin()+id+2, temp);

    aux[id] -= temp.size();
    aux.insert(aux.begin()+id+1, aux[id]); 
    aux.insert(aux.begin()+id+2, aux[id]+temp.size());
    id++;
  }

  while(id < aux.size()) {
    aux[id] += value.size();
    id++;
  }

  mSize += value.size();
  mCap += value.size();
}

#endif