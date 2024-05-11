#define ll long long
#define PB push_back
#define all(v) v.begin(), v.end()

class Solution {
public:
    ll maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        ll ans = 0LL, sum = 0LL;
        int n = nums1.size();
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            v.PB({nums2[i], nums1[i]});
        }
        sort(all(v), greater<pair<int, int>>());
        for(int j = 0; j < n; j++){
            sum += v[j].second;
            pq.push(v[j].second);
            if(pq.size() ==k){
                ans = max(ans, sum * v[j].first);
                sum -= pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};
