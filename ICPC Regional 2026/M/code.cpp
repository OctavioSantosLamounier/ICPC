#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
const long long INF = 4e18;

struct Graph {
    ii edges;
    int v;
};

struct Edge {
    long long dist, u;
    int k;

    bool operator>(const Edge& other) const {
        return dist > other.dist;
    }
};

int main() {
    int N, M, k;
    cin >> N >> M >> k;

    vector<vector<Graph>> G(N);
    int u, v, w1, w2;

    for(int i = 0; i < M; i++){
        cin >> u >> v >> w1 >> w2;
        --u; --v;

        G[u].push_back({{w1,w2}, v});
        G[v].push_back({{w1, w2}, u});
    }

    vector<vector<long long>> dp(N, vector<long long>(k+1, INF));

    priority_queue<
        Edge,
        vector<Edge>,
        greater<Edge>
    > pq;

    dp[0][k] = 0;
    pq.push({0, 0, k});

    while(!pq.empty()){
        Edge top = pq.top();
        pq.pop();
        
        long long dist = top.dist;
        int current = top.u, amount = top.k;

        if (current == N-1) {
            cout << dist << '\n';
            return 0;
        }

        for(Graph g: G[current]){
            w1 = g.edges.first, w2 = g.edges.second;
            int neighbor = g.v;

            if(dp[neighbor][amount] > dist + w1){
                dp[neighbor][amount] = dist + w1;
                pq.push({dp[neighbor][amount], neighbor, amount});
            }

            if(amount - 1 >= 0 && g.edges.second != -1 && dp[neighbor][amount-1] > dist + w2){
                dp[neighbor][amount-1] = dist + w2;
                pq.push({dp[neighbor][amount-1], neighbor, amount-1});
            }
        }

    }

    int biggest = *min_element(dp[N-1].begin(), dp[N-1].end());

    cout << biggest << '\n';
    return 0;
}

