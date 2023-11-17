// #include<bits/stdc++.h>
// using namespace std;

void replace(const T& x, list<T>& y) {
  //write your code here
  iterator it = begin();
  while(it!=end()) {
      // std::cout << *it << "\n";
    if(*it == x) {
      it = erase(it);
      for(iterator it2=y.begin();it2!=y.end();it2++) {
        insert(it, *it2);
      }
      
    } else {
      it++;
    }
  }
    
}
