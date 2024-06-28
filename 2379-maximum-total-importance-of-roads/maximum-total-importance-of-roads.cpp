struct CompareSecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; // Max heap based on the second value
    }
};

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int, int> degree;
        for (auto& r : roads) {
            int u = r[0], v = r[1];
            degree[u]++;
            degree[v]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecond> maxHeap;
        for (auto& it : degree) {
            maxHeap.push({it.first, it.second});
        }

        vector<int> val(n, 0);
        int m = n;
        while (!maxHeap.empty()) {
            pair<int, int> t = maxHeap.top();
            val[t.first] = m;
            m--;
            maxHeap.pop();
        }

        long long ans = 0;
        for (auto& r : roads) {
            int u = r[0], v = r[1];
            ans += val[u] + val[v];
        }

        return ans;
    }
};