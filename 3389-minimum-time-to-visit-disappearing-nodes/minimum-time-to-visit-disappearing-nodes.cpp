class Solution {
public:
     void dfs(vector<pair<int, int>> *adj, vector<int> &disappear, vector<int> &ans, int t, int u)
    {
        if (ans[u] == -1)
            ans[u] = t;
        else
            ans[u] = min(t, ans[u]);
        for (auto [v, w] : adj[u])
        {
            if (t + w < disappear[v] && (ans[v] == -1 || ans[v] > t + w))
            {
                ans[v] = t + w;
                dfs(adj, disappear, ans, t + w, v);
            }
        }
    }
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& d) {
       vector<pair<int, int>> gr[n];
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            gr[u].push_back({v, wt});
            gr[v].push_back({u, wt});
        }
        vector<int> dist(n,-1);
        dfs(gr,d,dist,0,0);
        return dist;
    }
};