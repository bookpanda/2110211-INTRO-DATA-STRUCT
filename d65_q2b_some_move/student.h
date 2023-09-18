#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  int i = std::lower_bound(aux.begin(), aux.end(), index) - aux.begin();
  // if(i == mData.size())
  //   i--;
  int vsize = value.size();

  if(index == 0) {
    mData.insert(mData.begin(), value);
    aux.insert(aux.begin(), value.size());
    i++;
  } else if(index == mSize) {
    std::cout << "i = " << i << "\n";
    mData.push_back(value);
    aux.push_back(aux.back());
    i++;
  } else if(mData[i].size() < 1870){ //use same vector
    int idx = i>0 ? index - aux[i-1] : index; 
    // std::cout << "idx: " << idx << "\n";
    mData[i].insert(mData[i].begin()+idx, value.begin(), value.end());
    // aux[i] += vsize;
  } else { //new vector, the over part of current one also to be behind value
    int idx = i>0 ? index - aux[i-1] : index; 
    std::vector<T> tmp;
    for(auto it=mData[i].begin()+idx;it!=mData[i].end();it++){
      tmp.push_back(*it);
    }
    mData[i].erase(mData[i].begin()+idx, mData[i].end());
    mData.insert(mData.begin()+i+1, value);
    mData.insert(mData.begin()+i+2, tmp);

    aux[i] -= tmp.size();
    aux.insert(aux.begin()+i+1, aux[i]);
    aux.insert(aux.begin()+i+2, aux[i]+tmp.size());
    i++;
  }

  // i++;
  while(i<aux.size()) {
    aux[i] += vsize;
    i++;
  }
  mSize+=vsize;
  mCap+=vsize;

}

#endif