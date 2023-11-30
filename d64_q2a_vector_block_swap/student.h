#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  if(a>b) std::swap(a, b);
  int ia = a - begin();
  int ib = b - begin();
  bool correct = ia>=0 && ia<mSize && ib>=0 && ib<mSize;
  if(m<=0 || ia+m-1 >= ib || !correct) return false;

  for(int i=0;i<m;i++) {
    std::swap(mData[ia+i], mData[ib+i]);
  }
  return true;
}

#endif
