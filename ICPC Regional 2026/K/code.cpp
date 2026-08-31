#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main() {
    fastio;

    int n;
    cin >> n;

    vector<pair<int,int>> c(n);

    long long sum=0;
    for (int i=0; i<n; i++) {
        cin >> c[i].second;
        sum += c[i].second;
    }

    for (int i=0; i<n; i++)
        cin >> c[i].first;
    
    for (int i=0; i<n; i++) 
        if (c[i].second < c[i].first) {
            cout << "-1" << endl;
            return 0;
        }
    
    long long maxi=0;
    for (int i=0; i<n; i++) 
        maxi = max(maxi, sum - (c[i].second - c[i].first));

    cout << maxi << endl;
    return 0;
}