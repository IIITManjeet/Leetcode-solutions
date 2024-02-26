class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mp;
        for(auto s:arr)mp[s]++;
        string ans="";
        for(auto s:arr){
            if(mp[s]==1){
                ans=s;
                k--;
                if(k==0)return ans;
            }
        }
        return "";
    }
};