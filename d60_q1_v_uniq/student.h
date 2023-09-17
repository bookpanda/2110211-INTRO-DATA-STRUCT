#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include<bits/stdc++.h>
using namespace std;

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  set<T> s;
  T *newData = new T[mCap]();
  int idx=0;
  for(int i=0;i<mSize;i++) {
    if(s.find(mData[i]) == s.end()) {
      s.insert(mData[i]);
      newData[idx] = mData[i];
      idx++;
    }
  }
  // for(int i=0;i<s.size();i++) {
  //   cout << newData[i] << " ";
  // } cout << "\n";
  delete [] mData;
  mData = newData;
  mSize = s.size();
}

#endif
