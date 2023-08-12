class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;
        for(auto it:s)m[it]++;
        for(auto it:t)m[it]--;
        for(auto it:m){
            if(it.second!=0)return false;
        }
        return true;
    }
};