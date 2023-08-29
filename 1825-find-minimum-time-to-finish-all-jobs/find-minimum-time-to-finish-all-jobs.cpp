class Solution {
public:
   void dfs(const vector<int>& jobs, vector<int>& workers, int curr, int& res) {
        if (curr == jobs.size()) {
            res = min(res, *max_element(workers.begin(), workers.end()));
            return;
        }

        unordered_set<int> seen;
        for (int i = 0; i < workers.size(); ++i) {
            if (seen.find(workers[i]) != seen.end()) continue;
            if (workers[i] + jobs[curr] >= res) continue;
            seen.insert(workers[i]);
            workers[i] += jobs[curr];
            dfs(jobs, workers, curr + 1, res);
            workers[i] -= jobs[curr];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> workers(k, 0);
        int res = INT_MAX;

        dfs(jobs, workers, 0, res);

        return res;
    }
};