#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio;

    int n;
    cin >> n;
    string s="";
    for (int a,i=0; i<=n; i++) {
        cin >> a;
        s += (a ? '1' : '0');
    }

    bitset<21> b(s);
    long long x = b.to_ullong();

    long long count = 0;
    while(x > 1) {
        if (x & 1) 
            x = (x ^ (x << 1)) - 1;
        else 
            x >>= 2;
        count++;
    }

    cout << count << endl;
    return 0;
}

/* 
1 1 0 1 0 /x           26 
0 1 1 0 1 (x+1)+1      13    

                        26 ^ 13 = 23 - 1 = 22 

1 0 1 1 0 /x           22 
0 1 0 1 1 (x+1)+1      11

                       22 ^ 11 = 29 - 1 = 28

1 1 1 0 0 /x           28 
0 1 1 1 0 /x           14

0 0 1 1 1 (x+1)+1      7

0 1 0 0 0 /x           8
0 0 1 0 0 /x           4
0 0 0 1 0 /x           2
0 0 0 0 1              1

/x move a cadeia a esquerda >>

se 1 usar operador xor com o atual e o anterior 

*/