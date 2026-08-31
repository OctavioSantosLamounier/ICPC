#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

int main(){ 
    fastio;
    int n;
    cin >> n;

    vector<int> nums(n);
    int c=0, v=0;

    for (int i=0; i<n; i++) {
        int a,b;
        cin >> a >> b;

        c += a;
        v += b;
        
        if (c==v) 
            nums[i] = 0;
        else    
            nums[i] = (c-v >= 0 ? 1 : -1);
    }

    int amount;
    cin >> amount;

    while (amount--) {
        int c;
        cin >> c;

        c--;
        if (nums[c] == 1)
            cout << "COMPRA" << endl;
        else if (nums[c] == -1)
            cout << "VENDA" << endl;
        else 
            cout << "NEUTRO" << endl;
    }
    return 0;
}