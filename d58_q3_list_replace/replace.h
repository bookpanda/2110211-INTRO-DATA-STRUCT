// #include<bits/stdc++.h>
// using namespace std;

void replace(const T& x, list<T>& y) {
  //write your code here
  iterator it = begin();
  while(it!=end()){
    if(*it == x){
      for(iterator it1=y.begin();it1!=y.end();it1++) {
        insert(it, *it1);
      }
      it = erase(it);
      it--;
    }
    it++;
  }
    
}
