#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  CP::vector<T> temp;
  for(auto it=first+k;it!=last;it++) {
    temp.push_back(*it);
    // std::cout << "TEMP " << *it << "\n";
  }
  int id = 0;
  for(auto it=first+k-1;it>=first;it--) {
    // std::cout << *(last-id) << "->" << *it << "\n";
    *(last-1-id) = *it;
    id++;
    // for(int i=0;i<mSize;i++) {
    //   std::cout << mData[i] << " ";
    // } std::cout << "\n"; 
  }
  id = 0;
  for(auto it=first;it!=last-k;it++) {
    *(it) = temp[id];
    id++;
  }
}

#endif
