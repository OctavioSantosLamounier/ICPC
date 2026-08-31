#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int n;
    cin >> n;

    int a=1,b=1;
    for (int i=1; i<=n; i++) {
        int c = b;
        b = a + b;
        a = c;
    }

    cout << a << endl;
    return 0;
}