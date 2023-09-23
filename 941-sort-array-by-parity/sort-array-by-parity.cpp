class Solution {
public:
    static bool comp(int a, int b){
        return a%2==0 && b%2==1;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp) ;
        return nums;
    }
};