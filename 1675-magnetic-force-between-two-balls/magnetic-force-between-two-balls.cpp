#define all(v) v.begin(), v.end()

class Solution {
public:
    bool check(vector<int>& position, int m, int force) {
        int cnt = 1;  // start from 1 since the first position is always placed
        int lastPlaced = position[0];
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - lastPlaced >= force) {
                cnt++;
                lastPlaced = position[i];
            }
            if(cnt >= m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(all(position));
        int l = 1, r = position.back() - position[0];
        int ans = 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(position, m, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
