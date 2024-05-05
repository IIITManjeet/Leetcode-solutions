class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        map<string, int> mp;
        int n = word.size();
        int c=0;
        for (int i = 0; i < n; i+=k) {
            string s = word.substr(i, k);
            mp[s]++;
            c++;
        }
        int f = 0;
        for (auto it : mp) {
            f = max(f, it.second);
        }
        return c - f;
    }
};