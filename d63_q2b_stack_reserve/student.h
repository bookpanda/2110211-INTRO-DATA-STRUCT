#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    int ra = mCap - mSize;
    int rb = other.mCap - other.mSize;
    if(ra > rb) return 1;
    if(ra == rb) return 0;
    return -1;
}

#endif
