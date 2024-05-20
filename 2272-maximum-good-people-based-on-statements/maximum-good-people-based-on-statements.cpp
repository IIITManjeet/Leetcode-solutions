class Solution {
public:
    bool validate(string& cur,vector<vector<int>>& s,int n){
        for(int i=0;i<n;i++){
            if(cur[i]=='1'){
                for(int j=0;j<n;j++){
                    if(s[i][j]!=2 and s[i][j]!=cur[j]-'0')return false;
                }
            }
        }
        return true;
    }
    void dfs(vector<vector<int>>& s,string& cur,int& ans,int n,int num,int i){
        if(i==n){
            if(validate(cur,s,n))ans=max(ans,num);
            return;
        }
        cur.push_back('1');
        dfs(s,cur,ans,n,num+1,i+1);
        cur.back()='0';
        dfs(s,cur,ans,n,num,i+1);
        cur.pop_back();
    }
    int maximumGood(vector<vector<int>>& s) {
        int n=s.size();
        string cur="";
        int ans=0;
        dfs(s,cur,ans,n,0,0);
        return ans;
    }
};