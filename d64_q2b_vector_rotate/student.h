#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  int st = first - begin();
  int ed = last - begin();
  int size = ed-st;
  T arr[k];
  int idx = 0;
  for(int i=st;i<st+k;i++) {
    arr[idx] = mData[i];
    idx++;
  }
  for(int i=st;i<ed-k;i++) {
    mData[i] = mData[i+k];
  }
  idx = 0;
  for(int i=ed-k;i<ed;i++){
    mData[i] = arr[idx];
    idx++;
  }
}

#endif
