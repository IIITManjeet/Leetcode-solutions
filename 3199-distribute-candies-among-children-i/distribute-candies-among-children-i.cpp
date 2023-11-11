class Solution {
public:
    int distributeCandies(int n, int limit) {
        // Define a lambda function for combinations
        auto comb = [](int x) -> long long {
            return 1LL * x * (x - 1) / 2;
        };

        // Check if n is greater than 3 times limit
        if (n > 3 * limit) {
            return 0;
        }

        long long ans = comb(n + 2);

        if (n > limit) {
            ans -= 3 * comb(n - limit + 1);
        }

        if (n - 2 >= 2 * limit) {
            ans += 3 * comb(n - 2 * limit);
        }

        // Return the final result
        return static_cast<int>(ans);
    }
};