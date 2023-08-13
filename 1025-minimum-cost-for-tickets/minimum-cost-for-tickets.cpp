class Solution {
public:
    unordered_set<int> isTravelNeeded;
    int solve(vector<int>& days, vector<int>& costs,vector<int>&dp,int index)
    {
        if(index>days[days.size()-1])return 0;
        if(isTravelNeeded.find(index)==isTravelNeeded.end())
        return solve(days,costs,dp,index+1);
        if(dp[index]!=-1)return dp[index];
        int oneDay=costs[0]+solve(days,costs,dp,index+1);
        int sevenDay=costs[1]+solve(days,costs,dp,index+7);
        int oneMonth=costs[2]+solve(days,costs,dp,index+30);
        return dp[index]=min(oneDay,min(sevenDay,oneMonth));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay=days[days.size()-1];
        vector<int>dp(lastDay+1,-1);
        for(auto &it:days){
            isTravelNeeded.insert(it);
        }
        return solve(days,costs,dp,1);
    }
};