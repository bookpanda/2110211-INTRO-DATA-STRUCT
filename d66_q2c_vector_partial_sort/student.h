#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include<bits/stdc++.h>
using namespace std;

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B
  std::vector<T> v;
  sort(pos.begin(), pos.end());
  for(iterator &it : pos) {
    // cout << "it = " << *it << "\n";
    v.push_back(*it);
  }
  sort(v.begin(), v.end(), comp);
  // for(auto &x: v) {
  //   cout << "v = " << x << "\n";
  // }
  int idx=0;
  for(iterator &it : pos) {
    *it = v[idx];
    idx++;
  }
}

#endif
