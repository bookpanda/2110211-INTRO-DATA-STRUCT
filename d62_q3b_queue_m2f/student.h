#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    int ed = (mFront+pos) % mCap;
    int save = mData[ed];
    for(int i=pos-1;i>=0;i--) {
        // std::cout << mData[(mFront+i+1)%mCap] << " to " << mData[(mFront+i)%mCap] << "\n";
        mData[(mFront+i+1)%mCap] = mData[(mFront+i)%mCap];
    }
    mData[mFront] = save;
    // std::cout <<  mData[mFront] << " to " << save << "\n";

}

#endif
