class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        long long mask = 0;
        unordered_map<long long, int> mp;
        mp[0]=1;
        for (char ch : word) {
            int bit = ch - 'a';
            mask ^= (1LL << bit);
            ans += mp[mask];
            for (int i = 0; i < 10; i++) {
                ans += mp[mask ^ (1LL << i)];
            }
            mp[mask]++;
        }
        return ans;
    }
};
