class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>,vector<int>>mp;
        for(int i=0;i<strs.size();i++){
            string st=strs[i];
            multiset<char>setstr;
            for(char ch:st){
                setstr.insert(ch);
            }
            mp[setstr].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            vector<int>v=it.second;
            vector<string>subAns;
            for(int i=0;i<v.size();i++)subAns.push_back(strs[v[i]]);
            ans.push_back(subAns);
        }
        return ans;
    }
};