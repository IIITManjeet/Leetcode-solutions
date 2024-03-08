class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        int mx=0;
        for(int i:nums){
            mp[i]++;
            mx=max(mx,mp[i]);
        }
        int maxFreq = 0;
        for (const auto& pair : mp) {
            maxFreq = max(maxFreq, pair.second);
        }
        int totalFreq = 0;
        for (const auto& pair : mp) {if (pair.second == maxFreq) {
            totalFreq += pair.second;
        }
    }

    return totalFreq;

    }
};