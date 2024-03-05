class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int>st;
        for(int n:nums)st.insert(n);
        for(int n:nums){
            if(st.find(n-1)==st.end()){
                int cur=n;
                int len=1;
                while(st.find(cur+1)!=st.end()){
                    len++;
                    cur++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};