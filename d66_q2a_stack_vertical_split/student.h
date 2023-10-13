#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  
  int sz = mSize / k;
  int r = mSize - k*sz;
  int idx=mSize-1;
  for(int i=0;i<k;i++) {
    int a=sz;
    if(r>0) {
      r--;
      a++;
    }
    output.push_back({});
    // std::cout << "box  " << k << " size = " << a << "\n";
    std::stack<T> tmp;
    for(int j=0;j<a;j++) {
      tmp.push(mData[idx--]);
      // std::cout << "A" << "\n";
    }
    while(!tmp.empty()){
      output.back().push(tmp.top());
      tmp.pop();
    }
  }
}

#endif
