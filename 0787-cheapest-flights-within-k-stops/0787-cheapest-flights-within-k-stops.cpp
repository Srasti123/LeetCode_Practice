class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // Queue for BFS: tuple of (city, cost, stops)
        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        int ans = INT_MAX;

        while (!q.empty()) {
            auto [u, cost, stops] = q.front();
            q.pop();

            if (u == dst) {
                ans = min(ans, cost);
                continue;
            }

            if (stops > K) continue;

            for (auto nei : adj[u]) {
                int v = nei.first;
                int price = nei.second;

                if (cost + price < minCost[v] || stops < K) {
                    minCost[v] = cost + price;
                    q.push({v, cost + price, stops + 1});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
