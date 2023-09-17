#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  K = std::min(K, mSize);
  for(int i=0;i<K;i++) {
    pop();
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //
  //don't forget to return an std::stack
  std::stack<T> s, ans;
  K = std::min(K, mSize);
  for(int i=0;i<K;i++) {
    T a = top();
    pop();
    s.push(a);
  }
  while(!s.empty()){
    ans.push(s.top());
    s.pop();
  }
  return ans;
}

#endif
