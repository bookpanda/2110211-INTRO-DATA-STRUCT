#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value) {
  // Your code here
  //1 if index is begin of vector, make new vector
  //2 if 
  // std::vector<int> d;
  // d.resize

  int vsize = value.size();

  int i = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
  if(i == mData.size())
    i--;

  // for(auto x: aux) {
  //   std::cout << x << " ";
  // } std::cout << "\n";

  if (i > 0)
    index -= aux[i - 1];
  mData[i].resize(vsize + mData[i].size());
  int newsize = mData[i].size();
  // std::cout << "newsize " << newsize << "\n";

  for(int j=newsize-1;j>=index+vsize;j--) {
    mData[i][j] = mData[i][j-vsize];
  }
  // for(auto x: mData[i]) {
  //   std::cout << x << " ";
  // } std::cout << "\n";
  
  for(int j=index;j<index+vsize;j++) {
    mData[i][j] = value[j-index];
  }
  // for(auto x: mData[i]) {
  //   std::cout << x << " ";
  // } std::cout << "\n";

  for(int j=i;j<mData.size();j++) {
    aux[j] += vsize;
  }
  mSize += vsize;
  mCap += vsize;

  
  // for(auto x: aux) {
  //   std::cout << x << " ";
  // } std::cout << "\n";
    // return mData[i][idx];
}

#endif