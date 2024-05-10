class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto comp = [&](pair<int, int>& a, pair<int, int>& b) {
            return (double)arr[a.first]/(double)arr[a.second]<(double)arr[b.first]/(double)arr[b.second];
        };
        vector<pair<int, int>> fractions;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                fractions.push_back({i, j});
            }
        }
        sort(fractions.begin(), fractions.end(), comp);
        return { arr[fractions[k - 1].first], arr[fractions[k - 1].second] };
    }
};