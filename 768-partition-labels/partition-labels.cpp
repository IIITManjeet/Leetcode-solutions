class Solution {
public:
    vector<int> partitionLabels(string s) {
    unordered_map<char,int>m;
    for(int i=0;i<s.size();i++){
        m[s[i]]=i;
    }
    vector<int>ans;
    int prev=-1,maxi=0;
    for(int i=0;i<s.size();i++){
        maxi=max(maxi,m[s[i]]);
        if(maxi==i){
            ans.push_back(maxi-prev);
            prev=maxi;
        }
    }
    return ans;
    }
};