class Solution {
public:
    long long calccost(int i, int mid, int r, vector<int>& ind, vector<long long>& pre) {
        long long cost = 0;
        if (mid) {
            int nd = upper_bound(ind.begin(), ind.end(), i - 2) - ind.begin() - 1;
            int strt = nd - mid + 1;
            cost += 1ll * i * mid - (pre[nd] - (strt ? pre[strt - 1] : 0));
        }
        if (r) {
            int strt = lower_bound(ind.begin(), ind.end(), i + 2) - ind.begin();
            int nd = strt + r - 1;
            cost += (pre[nd] - (strt ? pre[strt - 1] : 0)) - 1ll * i * r;
        }
        return cost;
    }
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int n = nums.size(); 
        long long res = LLONG_MAX;
        vector<int> ind;
        for (int i = 0; i < n; i++)
            if (nums[i])
                ind.push_back(i);
        vector<long long> pre;
        if (!ind.empty()) {
            pre.push_back(ind[0]);
            for (int i = 1; i < ind.size(); i++)
                pre.push_back(pre.back() + ind[i]);
        }
        for(int i=0;i<n;i++){
            int tempk = k, tempchanges = maxChanges;
            long long ops = 0;
            // center
            if (nums[i])
                tempk--;
            if (!tempk)
                return 0;
            //left
            if (i && nums[i - 1]) {
                tempk--;
                ops++;
            }
            if (!tempk) {
                res = min(res, ops);
                continue;
            }
            //right
            if (i + 1 < n && nums[i + 1]) {
                tempk--;
                ops++;
            }
            if (!tempk) {
                res = min(res, ops);
                continue;
            }
            //this as here we are doing for operation-1
            if (tempchanges >= tempk) {
                res = min(res, ops + tempk * 2);
                continue;
            }
            ops += tempchanges * 2;
            tempk -= tempchanges;
            int leftavail = upper_bound(ind.begin(), ind.end(), i - 2) - ind.begin();
            int rightavail = ind.end() - lower_bound(ind.begin(), ind.end(), i + 2);
            int leftl = max(tempk - rightavail, 0), lefth = min(tempk, leftavail);
            long long optimalops = LLONG_MAX;
            while (leftl <= lefth){
                int mid1 = leftl + (lefth - leftl) / 3, mid2 = lefth - (lefth - leftl) / 3;
            int r1 = tempk - mid1, r2 = tempk - mid2;
            long long cost1 = calccost(i, mid1, r1, ind, pre);
            long long cost2 = calccost(i, mid2, r2, ind,pre);
                optimalops = min({optimalops, cost1, cost2});
                if (cost1 < cost2)
                    lefth = mid2 - 1;
                else if (cost1 > cost2)
                    leftl = mid1 + 1;
                else {
                    leftl = mid1 + 1;
                    lefth = mid2 - 1;
                }
            }
            res = min(res, ops + optimalops);
        }
        return res;
    }
};