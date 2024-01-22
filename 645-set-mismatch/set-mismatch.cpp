class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>s;
        int mis=0,redu=0;
        for(int it:nums){
            if(s.find(it)!=s.end()){
                redu=it;
            }
            s.insert(it);
        }
        for(int i=1;i<=nums.size();i++){
            if(s.find(i)==s.end())mis=i;
        }
        return {redu,mis};
    }
};