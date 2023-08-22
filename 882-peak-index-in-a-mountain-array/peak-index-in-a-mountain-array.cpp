class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int flag=0;
        if(arr.size()==1)return 0;
        int ans=0;
        for(int i=0;i<arr.size()-2;i++){
            if(arr[i]<arr[i+1]&& arr[i+1]>arr[i+2]){
                ans=i+1;
                break;
            }
            continue;
        }
        return ans;
    }
};