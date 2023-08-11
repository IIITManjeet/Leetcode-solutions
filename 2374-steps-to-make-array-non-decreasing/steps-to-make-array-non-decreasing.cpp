class Solution {
public:
    int totalSteps(vector<int>& nums) {
        std::stack<pair<int,int>>st;
        int ans=0;
        st.push({nums[nums.size()-1],0});
        for(int i=nums.size()-2;i>=0;i--){
            int temp=0;
            while(!st.empty() && st.top().first<nums[i]){
                temp=max(temp+1,st.top().second);
                st.pop();
            }
            ans=max(ans,temp);
            st.push({nums[i],temp});
        }
        return ans;
    }
};