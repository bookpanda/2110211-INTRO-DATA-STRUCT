#include<bits/stdc++.h>
using namespace std;

int arr[1000005];
int main(){
    int n, pos, col;

    cin >> n >> pos >> col;
    for(int i=0;i<n+1;i++) {
        if(i == pos) {
            arr[i] = col;
        } else {
            int a;
            cin >> a;
            arr[i] = a;
        }
    }

    int l=pos,r=pos;
    int offset=0;
    while(l>=0 && r<=n && arr[l] == arr[r]) {
        while(arr[l] == arr[l-1] && l-1>=0) l--;
        while(arr[r] == arr[r+1] && r+1<=n) r++;
        // cout << "r = " << r << " l = " << l << "\n";

        if(r-l+1 - offset < 3) break;

        offset += r-l+1;
        l--;
        r++;
    }
    // cout << "ledft << " << l << " right " << r << "\n";
    for(int i=0;i<=n;i++) {
        if(i<=l || i>=r) {
            cout << arr[i] << " ";
        }
    }
}