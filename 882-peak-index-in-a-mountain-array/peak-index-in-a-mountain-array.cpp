class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int flag=0;
        int i = 0;
        while (arr[i] < arr[i + 1]) {
            i++;
        }
        return i;
    }
};