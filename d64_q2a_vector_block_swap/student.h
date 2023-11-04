#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  int ia = a - begin();
  int ib = b - begin();
  if(ia > ib) {
    std::swap(ia,ib);
    std::swap(a,b);
  }
  if(ia+m-1 >= ib || m<=0 || ia+m > mSize-1 || ib+m > mSize-1 || ia > mSize-1 || ib > mSize-1) return false;
  for(int i=0;i<m;i++) {
    std::swap(mData[ia+i], mData[ib+i]);
  }
  return true;
}

#endif
