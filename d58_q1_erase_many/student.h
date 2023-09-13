#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  // for(int i=pos.size()-1;i>=0;i--){
    // auto it = begin();
    // erase(it+pos[i]);
  // }
  int offset = 0;
  int idx = 0;
  int possize = pos.size();
  for(int i=0;i<mSize;i++) {
    // int a = 0;
    while(idx<possize && pos[idx] == i+offset) {
      offset++;
      idx++;
      mSize--;
      // a++;
      // std::cout << "SKIP " << pos[idx] << "\n";
    }
    // std::cout << mData[i] << " replaced by " << mData[i+offset] << "\n";
    mData[i] = mData[i+offset];
  }
  // mSize -= offset;
  // for(int i=0;i<mSize;i++) {
  //   std::cout << mData[i] << " ";
  // } std::cout << "\n";
}

#endif
