#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main() {
    fastio;

    int n;
    cin >> n;

    // decompoe o valor em binario
    vector<int> b(31,0);
    for (int e,j=0; j<n; j++) {
        cin >> e;
        for (int i=0; i<31; i++) 
            if ((1<<i & e))
                b[i]++;
    }

    // remotagem dos valores
    for (int j=0; j<n; j++) {
        int ans=0;
        for (int i=0; i<31; i++)
            if (b[i] > 0) {
                ans |= 1 << i;
                b[i]--;
            }
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}