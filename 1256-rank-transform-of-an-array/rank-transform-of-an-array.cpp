class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>st;
        for(auto it:arr)st.insert(it);
        map<int,int>mp;
        int i=1;
        for(auto it:st){
            mp[it]=i++;
        }
        for(auto &it:arr){
            it=mp[it];
        }
        return arr;
    }
};