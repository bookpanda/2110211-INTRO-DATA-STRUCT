#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  int idx=0;
  int posid=0;
  int cou=0;
  // std::cout << "-----------\n";
  for(int i=0;i<mSize;i++) {
    // std::cout << "i = " << i << "\n";
    if(posid < pos.size() && pos[posid] == i) {
      // std::cout << "pos[" << posid << "] = " << pos[posid] << "\n";
      posid++;
      // mSize--;
      cou++;
      continue;
    }
    mData[idx] = mData[i];
    idx++;
  }
  mSize -= cou;
}

#endif
