#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7 * 3;

int main() {
    int N;
    cin >> N;

    vector<int> nums(INF, 0);
    vector<int> indexs(N+1);

    nums[2] = 1;
    indexs[1] = 2;

    for(int i = 2; i <= N; i++){
        if(nums[i] != 0){
            indexs[i] = nums[i] * 3;
            nums[ indexs[i] ] = i;
        
        }else {
            int lastI = indexs[i-1];
            indexs[i] = lastI + 1;
            
            nums[lastI+1] = i;
        }    
    }

    cout << indexs[N] << '\n';

    return 0;
}

