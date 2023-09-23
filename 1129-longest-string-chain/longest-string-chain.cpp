class Solution {
public:
    bool check(string& s1,string& s2){
        if(s1.size()!=s2.size()+1)return false;
        int l=0,r=0;
        while(l<s1.size()){
            if(s1[l]==s2[r]){
                l++;r++;
            }
            else{
                l++;
            }
        }
        if(l==s1.size() && r==s2.size())return true;
        return false;
    }
    static bool comp(string& s1,string& s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i],words[prev]) && dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};