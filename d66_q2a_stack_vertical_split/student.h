#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  int sz = mSize/k;
  int offset=0;
  int quota = mSize - sz*k;
  for(int i=0;i<k;i++) {
    int rsz = sz;
    if(quota) {
      quota--;
      rsz++;
    }
    CP::stack<T> s;
    for(int j=0;j<rsz;j++) {
      // std::cout << "idx =  " << mSize-1-(j+offset) << "\n";
      s.push(mData[mSize-1-(j+offset)]);
    }
    offset += rsz;
    output.push_back({});
    while(!s.empty()) {
      // std::cout << "push " << s.top() << "\n";
      output.back().push(s.top());
      s.pop();
    }
  }
}

#endif
