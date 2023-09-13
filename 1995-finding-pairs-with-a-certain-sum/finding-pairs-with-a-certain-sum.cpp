class FindSumPairs {
public:
    vector<int>v1,v2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;v2=nums2;
        sort(v1.begin(),v1.end());
        for(auto it:nums2)mp[it]++;
    }
    
    void add(int index, int val) {
        mp[v2[index]]--;
        v2[index]+=val;
        mp[v2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        int n1=v1.size();
        
        for(int i=0;i<n1;i++)
        {
            if(v1[i]>=tot)  
                break;
            ans+=mp[tot-v1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(mp1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */