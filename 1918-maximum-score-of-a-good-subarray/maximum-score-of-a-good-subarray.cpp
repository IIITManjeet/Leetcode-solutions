class Solution {
public:
    vector<int>NSL(vector<int>& nums){
        stack<int> s;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.empty())res.push_back(-1);
            else{
                res.push_back(s.top());
            }
            s.push(i);
        }
        return res;
    }
    vector<int>NSR(vector<int>& nums){
        stack<int> s;
        vector<int>res;
        for(int i=nums.size()-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.empty())res.push_back(nums.size());
            else{
                res.push_back(s.top());
            }
            s.push(i);
        }
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> nsl=NSL(nums);
        vector<int> nsr=NSR(nums);
        reverse(nsr.begin(),nsr.end());
        int score=0;
        for(int i=0;i<nums.size();i++){
            int l=nsl[i];
            int r=nsr[i];
            if(l+1<=k && r-1>=k){
                score=max(score,nums[i]*(r-l-1));
            }
        }
        return score;
    }
};