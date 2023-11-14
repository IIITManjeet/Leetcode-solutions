class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,-1),last(26,-1);
        for(int i=0;i<s.size();i++){
            int cur=s[i]-'a';
            if(first[cur]==-1)first[cur]=i;
            last[cur]=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(first[i]==-1)continue;
            unordered_set<char>bet;
            for(int j=first[i]+1;j<last[i];j++){
                bet.insert(s[j]);
            }
            ans+=bet.size();
        }
        return ans;
    }
};