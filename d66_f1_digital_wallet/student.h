#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <string>

// you can include anything
#include<bits/stdc++.h>

using namespace std;

class DigitalWallet {
  // you can declare variables or write new function
  int time=0;
  long long total_give=0;
  long long total_spent=0;
  long long total_expired=0;
  std::unordered_map<string, multiset<pair<int,int> > > wallets;
  // std::map<string, 
  //may need mapof total current money for each person with
  //marker that whether it is updated
  std::unordered_map<string, pair<int, int> > current;
  std::multiset<pair<int,string> > exp;

 protected:
  void remove_expired(size_t time, string id) {
    auto it = wallets[id].begin();
    while(wallets[id].size() > 0 && it->first < time) {
      total_expired += it->second;
      current[id].first -= it->second;
      wallets[id].erase(it);
      it = wallets[id].begin(); //sus
    }
  }


 public:
  void add_money(size_t time, string id, int amount, size_t duration) {
    // your code here
    time = time;
    total_give += amount;
    wallets[id].insert({time+duration, amount});
    current[id].first += amount;
    exp.insert({time+duration, id});
  }

  bool use_money(size_t time, string id, int amount) {
    // your code here
    time = time;
    remove_expired(time, id);
    int sum=0;
    int idx=0;
    bool enough = false;
    for(auto it2=wallets[id].begin();it2!=wallets[id].end();it2++) {
      sum += it2->second;
      idx++;
      if(sum >= amount) {
        enough = true;
        break;
      }
    }
    // cout << "emought " << enough << "\n";
    if(!enough) return false;
    total_spent += amount;
    for(int i=0;i<idx-1;i++) {
      auto it = wallets[id].begin();
      amount -= it->second;
      current[id].first -= it->second;
      wallets[id].erase(it);
    }
    auto it3 = wallets[id].begin();
    current[id].first -= amount;
    int left = it3->second - amount;
    int expiry = it3->first;
    wallets[id].erase(it3);
    wallets[id].insert({expiry, left});
    // current[id].second = false;
    return true;
  }

  int current_money(size_t _time, string id) {
    // your code here
    time = _time;

    remove_expired(time, id);
    // if(current[id].second) {
    //   return current[id].first;
    // }
    // int sum=0;
    // for(auto it2=wallets[id].begin();it2!=wallets[id].end();it2++) {
    //   sum += it2->second;
    // }
    // current[id] = {sum, true};
    return current[id].first;
    // return sum;
  }

  void status(size_t _time, long long &_total_give, long long &_total_spent,
              long long &_total_expired) {
    // your code here
    time = _time;
    auto it = exp.begin();
    while(exp.size() > 0 && it->first < time) {
      remove_expired(time, it->second);
      exp.erase(it);
      it = exp.begin(); //sus
    }
    // for(auto it=exp.begin();it!=exp.end();it++) {
    //   remove_expired(time, it->second);
    // }
    _total_give = total_give;
    _total_spent = total_spent;
    _total_expired = total_expired;
    return;;
  }
};

#endif
