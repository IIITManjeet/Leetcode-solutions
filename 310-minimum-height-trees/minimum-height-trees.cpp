#define rep(i, a, b) for (int i = a; i <= b; i++)
#define PB push_back
typedef vector<int> vi;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         if (n == 1) return {0};

        map<int, vector<int>> g;
        vector<int> degree(n, 0);
        rep(i, 0, edges.size() - 1) {
            int u = edges[i][0];
            int v = edges[i][1];
            g[u].PB(v);
            g[v].PB(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> leaves;
        rep(i, 0, n-1) {
            if (degree[i] == 1) leaves.push(i);
        }
        while (n > 2) {
            int size = leaves.size();
            n -= size;
            for (int i = 0; i < size; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : g[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) leaves.push(neighbor);
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.PB(leaves.front());
            leaves.pop();
        }

        return result;
    }
};