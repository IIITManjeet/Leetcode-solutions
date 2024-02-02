class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        set<int>st;
        for(int i=1;i<=9;i++){
            int cur=i;
            int next=i+1;
            while(cur<=high and next<=9){
                cur=cur*10+next;
                if(cur>=low and cur<=high){
                    st.insert(cur);
                }
                next++;
            }
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};