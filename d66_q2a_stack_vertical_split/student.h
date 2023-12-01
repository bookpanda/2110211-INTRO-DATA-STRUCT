#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  int sz = mSize/k;
  int quota = mSize - k*sz;

  int i=mSize-1;
  output.resize(k);
  int idx=0;
  while(i>=0) {
    int vz = sz;
    if(quota) {
      quota--;
      vz++;
    }
    std::stack<T> s;
    for(int j=0;j<vz;j++) {
      s.push(mData[i]);
      i--;
    }

    while(!s.empty()) {
      output[idx].push(s.top());
      s.pop();
    }
    idx++;
  }
}

#endif
