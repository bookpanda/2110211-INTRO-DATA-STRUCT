#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
  // Your code here
  aux = !aux;
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
    return aux ? mData[(mFront+mSize-1)%mCap] : mData[mFront];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  return aux ? mData[mFront] : mData[(mFront+mSize-1)%mCap];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  if(aux==0) {
    mData[(mFront + mSize) % mCap] = element;
  } else {
    mFront = (mFront-1+mCap) % mCap;
    mData[mFront] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if(aux==0) {
    mFront = (mFront + 1) % mCap;
  }
  mSize--;

  // std::cout << "\n";
  // for(int i=0;i<mCap;i++) {
  //   std::cout << mData[i] << " ";
  // } std::cout << "\n" << "mFront : " << mFront << ", val = " << front() << "   back = " << back() << "\n\n";
}

#endif