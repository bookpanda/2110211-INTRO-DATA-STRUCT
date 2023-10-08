#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here
  CP::vector<T> v;
  int cou = 0;
  int sz = last-first;
  for(auto it=first;it!=last;it++) {
    v.push_back(*it);
    cou++;
    if(cou == k) break;
  }
  // std::cout << "\nstore\n";
  // for(auto x: v){
  //   std::cout << x << " ";
  // } std::cout << "\n";
  int idx=0;
  for(auto it=first;it!=first+(sz-k);it++) {
    // std::cout << *it << " -> " << *(it+k+idx) <<  "\n";
    *it = *(it+k);
  }

  idx=0;
  for(auto it=first+(sz-k);it!=last;it++) {
    // std::cout << *it << " => " << v[(idx)%v.size()] <<  "\n";
    *it = v[(idx)%v.size()];
    idx++;
  }
}

#endif
