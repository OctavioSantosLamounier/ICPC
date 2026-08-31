#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    set<int> s = {1,2,3,4};

    for(int e, i=0; i<10; i++){
        cin >> e;
        s.erase(e);
    }

    cout << s.size() << endl;
    return 0;
}