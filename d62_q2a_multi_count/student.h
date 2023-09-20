#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    std::map<T,int> mp;
    for(int i=0;i<mSize;i++) {
        int idx = (mFront+i) % mCap;
        if(mp.find(mData[idx]) == mp.end()) {
            mp[mData[idx]] = 1;
        } else {
            mp[mData[idx]]++;
        }
    }
    std::vector<std::pair<T,size_t> > v;
    for(auto x: k) {
        v.push_back({x, mp[x]});
    }

    return v;
}

#endif
