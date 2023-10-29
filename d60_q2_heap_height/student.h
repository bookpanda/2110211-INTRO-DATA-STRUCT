#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  if(mSize==0) return -1;
  int idx=0;
  int lvl=0;
  while(idx<mSize) {
    idx = (idx*2)+1;
    lvl++;
  }
  return lvl-1;
}

#endif

