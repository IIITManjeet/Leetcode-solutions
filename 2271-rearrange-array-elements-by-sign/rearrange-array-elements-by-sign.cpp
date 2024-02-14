class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>a1,a2;
        for(auto num:nums){
            if(num<0)a1.push_back(num);
            else a2.push_back(num);
        }
        vector<int>ans;
        int i=0,j=0;
        for(;i<a1.size() && j<a2.size();i++,j++){
            ans.push_back(a2[j]);
            ans.push_back(a1[i]);
        }
        while(i<a1.size()){
            ans.push_back(a1[i++]);
        }
        while(j<a2.size()){
            ans.push_back(a2[j++]);
        }
        return ans;
    }
};