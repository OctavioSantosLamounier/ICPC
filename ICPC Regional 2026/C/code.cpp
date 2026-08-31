#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    
    int t,c,k;
    cin >> t >> c >> k;

    int ans = min((t*k),c);
    
    cout << ans << endl;
    return 0;
}