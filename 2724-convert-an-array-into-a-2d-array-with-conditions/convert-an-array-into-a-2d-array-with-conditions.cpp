class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int number = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            number = max(number, mp[nums[i]]);
        }
        
        vector<vector<int>> v(number);
        for(auto a: mp){
            int num = a.first;
            int freq = a.second;

            for(int i =0;i<freq;i++){
                v[i].push_back(num);
            }
        }
        return v;
    }
};
