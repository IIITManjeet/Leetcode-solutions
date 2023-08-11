class Solution {
public:
    int dp[301];
    bool helper(int index,string s,vector<string>& wordDict){
        if(index==s.size())return true;
        if(dp[index]!=-1)return dp[index];
        string temp;
        for(int j=index;j<s.size();j++){
            temp+=s[j];
            if(count(wordDict.begin(),wordDict.end(),temp)){
                if(helper(j+1,s,wordDict))return dp[index]=true;
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof dp);
        return helper(0,s,wordDict);
    }
};