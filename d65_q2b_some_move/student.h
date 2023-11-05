#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  auto it = std::lower_bound(aux.begin(), aux.end(), index);//aux=10 -> idx=9
  int auxid = it - aux.begin();
  if(mData[auxid].size() > 2000) { //new vector
    int st = auxid>0 ? index - aux[auxid-1] : index;
    std::vector<T> tmp;
    for(int i=st;i<mData[auxid].size();i++) {
      tmp.push_back(mData[auxid][i]);
    }
    mData.insert(mData.begin() + auxid+1, tmp);
    aux.insert(aux.begin() + auxid+1, aux[auxid]);
    
    aux[auxid] -= mData[auxid].size() - st;
    mData[auxid].erase(mData[auxid].begin() + st, mData[auxid].end());

    mData.insert(mData.begin() + auxid+1, value);
    aux.insert(aux.begin() + auxid+1, aux[auxid]);

  } else { //use current vector
    int st = auxid>0 ? index - aux[auxid-1] : index;
    mData[auxid].insert(mData[auxid].begin() + st, value.begin(), value.end());
    aux[auxid] += value.size();
  }

  for(int i=auxid+1;i<aux.size();i++) {
    aux[i] += value.size();
  }

  mSize += value.size();
  mCap += value.size();
}

#endif