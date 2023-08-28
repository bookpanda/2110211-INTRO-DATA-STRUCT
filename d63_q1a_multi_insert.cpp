#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
  //write your code here
  //v.insert(v.begin()+position, count, value);
  vector<int> va;
  int vsize=v.size();
  for(int i=0;i<vsize;i++) {
    if(i==position){
      for(int j=0;j<count;j++) {
        va.push_back(value);
      }
      va.push_back(v[i]);
    } else{
      va.push_back(v[i]);
    }
  }
  if(position==vsize){
    for(int j=0;j<count;j++){
      va.push_back(value);
    }
  }
  v=va;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
int n,value,position,count;
cin >> n >> value >> position >> count; vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];
multiple_add(v,value,position,count);
  cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
  for (auto &x : v) cout << x << " ";
  cout << endl;
 }
