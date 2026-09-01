#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
typedef vector<vector<char>> matriz;


int verificar (matriz v1, matriz v2) {
    if (v1.size() != v2.size() || v1[0].size() != v2[0].size())
        return 1;

    int n = v1.size();
    int m = v1[0].size();

    for (int i=0; i<n; i++) 
        for (int j=0; j<m; j++) 
            if (v1[i][j] != v2[i][j]) 
                return 1;

    return 0;
}

matriz gira (matriz mInicial) {
    int n = mInicial.size();
    int m = mInicial[0].size();
    
    matriz mFinal(m, vector<char>(n));

    for (int i=0; i<n; i++) 
        for (int j=0; j<m; j++) 
            mFinal[j][n-i-1] = mInicial[i][j];

    return mFinal;
}

matriz flipar (matriz mInicial) {
    int n = mInicial.size();
    int m = mInicial[0].size();
    
    matriz mFinal(n, vector<char>(m));

    for (int i=0; i<n; i++) 
        for (int j=0; j<m; j++) 
            mFinal[i][m-j-1] = mInicial[i][j];

    return mFinal;
}


int main() {
    fastio;

    int n,m;
    cin >> n >> m;

    vector<vector<char>> v1(n, vector<char> (m));
    vector<vector<char>> v2(n, vector<char> (m));

    for (int i=0; i<n; i++) 
        for (int j=0; j<m; j++) 
            cin >> v1[i][j];

    int aux=8;
    
    // gira 90 
    v2 = gira(v1);
    aux -= verificar(v1,v2);
    // gira 180
    v2 = gira(v2);
    aux -= verificar(v1,v2);
    // gira 270
    v2 = gira(v2);
    aux -= verificar(v1,v2);
   
    // girar no proprio eixo
    v2 = flipar(v1);
    aux -= verificar(v1,v2);

    // gira 90 
    v2 = gira(v2);
    aux -= verificar(v1,v2);
    // gira 180
    v2 = gira(v2);
    aux -= verificar(v1,v2);
    // gira 270
    v2 = gira(v2);
    aux -= verificar(v1,v2);

    cout << aux << endl;
    return 0;
}