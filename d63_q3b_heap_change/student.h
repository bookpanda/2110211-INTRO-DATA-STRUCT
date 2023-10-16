#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <assert.h>

template <typename T,typename Comp>
void CP::priority_queue<T,Comp>::change_value(size_t pos,const T& value) {
  //write your code here
  mData[pos] = value;
  int pidx = (pos-1)/2;
  if(pidx>=0 && mLess(mData[pidx], mData[pos])) {
    fixUp(pos);
  } else {
    fixDown(pos);
  }
}

#endif
