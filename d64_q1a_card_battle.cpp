#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> card[500112];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    int o[500112];
    map<int, int> toe;
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(toe.find(a) == toe.end())
            toe[a] = 0;
        toe[a] += 1;
    }
    for(int i=0;i<m;i++) {
        cin >> o[i];
        for(int j=0;j<o[i];j++) {
            int a;
            cin >> a;
            card[i].push_back(a);
        }
    }
//    for(auto x: toe){
//        cout << x.first << " " << x.second << endl;
//    }
    int flag = 0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<o[i];j++) {
            auto it = toe.upper_bound(card[i][j]);
            if(it != toe.end()) {
//                cout << "use " << it->first << endl;
                it->second -= 1;
                if(it->second == 0)
                    toe.erase(it->first);
            } else {
                cout << i+1 << endl;
                flag = 1;
            }
            if(flag==1) break;
        }
        if(flag==1) break;
    }
    if(flag==0)
    cout << m+1 << endl;

    return 0;
}
