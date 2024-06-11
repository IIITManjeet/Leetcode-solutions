#define all(v) v.begin(), v.end()
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        vector<int>rem;
        vector<int>ans;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            int cnt=mp[arr2[i]];
            for(int  j=0;j<cnt;j++){
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        for(auto it:mp){
            for(int i=0;i<it.second;i++){
                rem.push_back(it.first);
            }
        }
        sort(all(rem));
        for(auto it:rem)ans.push_back(it);
        return ans;
    }
};