class Solution {
public:
    unordered_map<int,int>hash;
    bool solve(vector<int>& stones, int n, int index, int prev,
    vector<vector<int>> &dp){
        if(index==n-1)return 1;//last stone
        if(dp[index][prev]!=-1)return dp[index][prev];//if already calculated
        int ans=false;
        for(int i=prev-1;i<=prev+1;i++){
            if(i>0 && hash.find(stones[index]+i)!=hash.end()){
                ans=ans || solve(stones,n,hash[stones[index]+i],i,dp);
            }
        }
        return dp[index][prev]=ans;

    }
    bool canCross(vector<int>& stones) {
    vector<vector<int>> dp(2001,vector<int>(2001,-1));
        for(int i=0;i<stones.size();i++){
            hash.insert({stones[i],i});
        }
        return solve(stones, stones.size(), 0, 0,dp);
    }
};