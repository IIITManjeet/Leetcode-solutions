class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxCoins(vector<int> &piles) {
        int n = piles.size();
        int third = n / 3;
        nth_element(piles.begin(), piles.begin() + third, piles.end());
        sort(piles.begin() + third, piles.end());
        int sum = 0;
        for(int i = third; i < n; i += 2) {
            sum += piles[i];
        }
        return sum;
    }
};