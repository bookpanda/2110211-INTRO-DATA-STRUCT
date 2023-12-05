#include<bits/stdc++.h>
using namespace std;

namespace CP{
    template<class Key, class T>
    class geometric_hash_grid {
        protected:
            // เพิ่มฟังก์ชันหรือข้อมูลใด ๆ ได้
            unordered_map<pair<int,int >, unordered_map<T, int> > mData;

        public:
            gometric_hash_grid() : mData() {
                
            }
            void insert(int x, int y, const T& data) {
                mData[{x,y}][data] += 1;
            }
            void remove(int x, int y, const T& data) {
                mData[{x,y}][data] = max(0, mData[{x,y}][data]-1);
            }
            std::vector<T> getDataAt(int x, int y) {
                std::vector<T> ans;
                for(auto it: mData[{x,y}])//first = T, second = count
                for(int i=0;i<it.second;i++)
                ans.push_back(it.first);
                
                return ans;
            }
            std::vector<T> neighbors(int x, int y) {
                std::vector<T> ans;
                for(int i=x-1;i<=x+1;i++)
                for(int j=y-1;j<=y+1;j++)
                for(auto &z: getDataAt(i,j)) {
                    ans.push_back(z);
                }
                
                return ans;
            }
    };
}