#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  if(mSize == 0) return -1;
  int cou=0;
  int a = 1;
  int b = mSize;
  while(b > 0) {
    b -= a;
    a *= 2;
    cou++;
  }
  return cou-1;
}

#endif

