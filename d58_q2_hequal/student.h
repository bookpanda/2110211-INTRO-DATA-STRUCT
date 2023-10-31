#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  //write your code here
  if(mSize != other.mSize) return false;
  CP::priority_queue<T, Comp> q1(*this), q2(other);
  while(!q1.empty()) {
    if(q1.top() != q2.top()) return false;
    q1.pop();
    q2.pop();
  }
  return true; // you can change this line
}

#endif
