class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < meetings.size(); i++) {
            int u = meetings[i][0], v = meetings[i][1], wt = meetings[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> prior(n, INT_MAX);
        prior[0]=0;
        prior[firstPerson] = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({firstPerson, 0});
        
        while (!q.empty()) {
            int p = q.front().first;
            int time = q.front().second;
            q.pop();
            for (auto [next, t] : adj[p]) {
                if (t >= time && t < prior[next]) {
                    prior[next] = t;
                    q.push({next, t});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (prior[i] != INT_MAX) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};