#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main() {
    fastio;

    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            cin >> m[i][j];  
    
    // quina superior esquerda
    if (m[0][0] < m[0][1] && m[0][0] < m[1][0])
        cout << 0 << endl;

    // quina superior direita
    if (m[0][n-1] < m[0][n-2] && m[0][n-1] < m[1][n-1])
        cout << 1 << endl;

    // quina inferior direita
    if (m[n-1][n-1] < m[n-1][n-2] && m[n-1][n-1] < m[n-2][n-1])
        cout << 2 << endl;
    
    // quina inferior esquerda
    if (m[n-1][0] < m[n-1][1] && m[n-1][0] < m[n-2][0])
        cout << 3 << endl;

    return 0;
}

/* 
4
15 9 7 3 
16 14 10 4
20 17 11 6
25 22 19 12

3
300 250 150
280 200 140 
240 190 130 

2
2 4
1 3
*/