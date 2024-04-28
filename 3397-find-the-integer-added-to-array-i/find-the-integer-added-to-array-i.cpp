#define all(v) v.begin(), v.end()
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(all(nums1));
        sort(all(nums2));
        return (nums2[0]-nums1[0]);
    }
};