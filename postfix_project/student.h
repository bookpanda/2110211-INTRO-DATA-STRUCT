#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  //WRITE YOUR CODE HERE
  //DON"T FORGET TO RETURN THE RESULT
  stack<int> s;
  for(auto x: v) {
    int comm = x.first;
    if(comm == 0) {
      int op = x.second;
      int a2 = s.top();
      s.pop();
      int a1 = s.top();
      s.pop();
      if(op == 0) {
        s.push(a1+a2);
      } else if(op == 1) {
        s.push(a1-a2);
      } else if(op == 2) {
        s.push(a1*a2);
      } else if(op == 3) {
        s.push(a1/a2);
      }
    } else if(comm == 1) {
      int operand = x.second;
      s.push(operand);
    } 
  }
  return s.top();
}

#endif
