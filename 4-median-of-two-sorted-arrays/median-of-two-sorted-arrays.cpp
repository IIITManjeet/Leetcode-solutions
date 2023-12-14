class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]>nums2[j])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else
            {
                v.push_back(nums1[i]);
                i++;
            }
        }
        while(i<nums1.size())
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size())
        {
            v.push_back(nums2[j]);
            j++;
        }
        double med=0.0;
        int m=v.size()/2;
        if(v.size()%2==0)
        {
           med=(v[m-1]+v[m])/2.00;
        }
        else
        {
            med=v[m];
        }
        return med;
    }
};