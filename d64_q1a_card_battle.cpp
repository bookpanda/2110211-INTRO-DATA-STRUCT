#include<bits/stdc++.h>
using namespace std;

map<int,int> toe;
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m;

    cin >> n >> m;

    while(n--) {
        int power;
        cin >> power;
        toe[power] += 1;
    } 
    // for(auto x: toe){
    //     cout << "toe[" << x.first << "] = " << x.second << endl;
    // }
    int ans=0;
    bool lose = false;
    for(int i=0;i<m;i++) {
        int amou;
        // cout << "round  " << i << endl;
        cin >> amou;
        while(amou--) {
            int power;
            cin >> power;
            auto it = toe.upper_bound(power);
            // cout << "it " << it->first << " , " <<  it->second << endl;
            if(it != toe.end() && it->second > 0) {
                it->second -= 1;
                if(it->second == 0) toe.erase(it);

                // cout << "use " << it->first << endl;
                // cout << "now have " << it->second << endl;
            } else {
                lose = true;
            }
        }
        if(!lose) {
            ans++;
        }
    }
    cout << ans+1 << endl;
}