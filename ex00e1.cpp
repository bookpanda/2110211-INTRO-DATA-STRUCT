#include <iostream>

using namespace std;

int main()
{
    int h,m;
    int mins;
    cin >> h >> m;
    cin >> mins;
    int hour = mins / 60;
    int r = mins % 60;
    h = (h+hour) % 24;
    m += r;
    if(m >= 60) {
        m -= 60;
        h = (h+1) % 24;
    }

    if(h < 10) {
        cout << "0";
    }
    cout << h << " ";

    if(m < 10) {
        cout << "0";
    }
    cout << m << endl;

    return 0;
}
