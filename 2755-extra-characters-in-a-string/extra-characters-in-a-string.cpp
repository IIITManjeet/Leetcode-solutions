class Solution {
public:
    int solve(string& s, unordered_map<string, int>&mp, int index,vector<int>&dp){
        if (index >= s.size()) return 0;
        if (dp[index] != -1) return dp[index];
         string currStr = "";
        int minExtra = s.size();
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
            int currExtra = (mp.count(currStr))? 0 : currStr.size();
            int nextExtra = solve(s, mp, cutIdx + 1,dp);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        return dp[index]=minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, int>mp;
        vector<int>dp(s.size(), -1);
        for (string& word : dictionary) mp[word]++;
        
        int ans = solve(s, mp, 0,dp);
        return ans;
    }
};