class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int,int>mp;
        for(int &i :banned) mp[i]++;
        int sum=0,cnt=0;
        for(int i=1; i<=n; i++){
            if(((sum+i)<=maxSum) && (mp.find(i)==mp.end())){
                cnt++;
                sum+=i;
            }
        }
        return cnt;
    }
};