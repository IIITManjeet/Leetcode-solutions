class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        // if(k>=n)return *max_element(arr.begin(),arr.end());
        int maxEl=arr[0];
        for(auto it:arr){
            maxEl=max(maxEl,it);
        }
        int cur=arr[0],streak=0;
        for(int i=1;i<n;i++){
            if(cur>arr[i]){
                streak++;
            }
            else{
                cur=arr[i];
                streak=1;
            }
            if(streak==k || cur==maxEl)return cur;
        }
        return -1;
    }
};