class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& f : flights) {
            graph[f[0]].emplace_back(f[1], f[2]);
        }

        // dist[node][stops] = min cost to reach node using `stops` edges
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        // Min-heap: {cost, node, steps}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, src, 0);

        while (!pq.empty()) {
            auto [cost, u, steps] = pq.top();
            pq.pop();

            if (steps > k + 1) continue;  // more than k edges → skip
            if (u == dst) return cost;    // reached destination

            for (auto& [v, price] : graph[u]) {
                int newCost = cost + price;
                if (steps + 1 <= k + 1 && newCost < dist[v][steps + 1]) {
                    dist[v][steps + 1] = newCost;
                    pq.emplace(newCost, v, steps + 1);
                }
            }
        }

        return -1;
    }
};