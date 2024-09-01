class Solution {
public:
    const int INF = 2e9;
    typedef pair<int, int> pi;

    int dijkstra(int n, int src, int dest, vector<pi> adj[]) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (u == dest) break;
            for (auto [c, v] : adj[u]) {
                if (cost + c < dist[v]) {
                    dist[v] = cost + c;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        vector<pi> adj[n];

        for (auto &e : edges) {
            if (e[2] != -1) {
                adj[e[0]].push_back({e[2], e[1]});
                adj[e[1]].push_back({e[2], e[0]});
            }
        }

        int dist = dijkstra(n, src, dest, adj);
        if (dist < target) return {};

        bool equal = dist == target;

        for (auto &e : edges) {
            if (e[2] == -1) {
                e[2] = equal ? INF : 1;
                adj[e[0]].push_back({e[2], e[1]});
                adj[e[1]].push_back({e[2], e[0]});

                if (!equal) {
                    int newDist = dijkstra(n, src, dest, adj);
                    if (newDist <= target) {
                        equal = true;
                        e[2] += target - newDist;
                    }
                }
            }
        }

        return equal ? edges : vector<vector<int>>{};
    }
};
