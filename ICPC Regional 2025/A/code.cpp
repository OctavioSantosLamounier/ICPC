#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m,0);

    for(int i=0; i<n; i++) 
        for(int e,j=0; j<m; j++){
            cin >> e;
            v[j] = max(v[j], e);
        }
    
    int ans=0;
    for(int i: v)
        ans += i;

    cout << ans << endl;
    
    return 0;
}