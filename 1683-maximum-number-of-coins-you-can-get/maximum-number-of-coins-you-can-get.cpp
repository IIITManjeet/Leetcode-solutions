class Solution {
public:
    Solution() {
        // Optimizing input/output in C++
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int maxCoins(vector<int>& piles) {
        // Get the size of the input vector
        int n = piles.size();

        // Calculate one-third of the size of the vector
        int third = n / 3;

        // Use nth_element to partition the vector and get the middle one-third element
        nth_element(piles.begin(), piles.begin() + third, piles.end());

        // Sort the middle one-third of the vector
        sort(piles.begin() + third, piles.end());

        // Initialize a variable to keep track of the sum of coins
        int sum = 0;

        // Iterate over the sorted one-third of the vector, considering every other element
        for (int i = third; i < n; i += 2) {
            sum += piles[i];
        }

        // Return the calculated sum, representing the maximum sum of coins
        return sum;
    }
};
