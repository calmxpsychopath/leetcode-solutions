class Solution {
private:
    std::array<int, 26> dp;

public:
    int longestIdealString(std::string s, int k) {
        int sz = s.size();
        std::fill(dp.begin(), dp.end(), 0);

        int idx = s[0] - 'a';
        dp[idx] = 1;
        for (int i = 1; i < sz; i++) {
            idx = s[i] - 'a';

            dp[idx] += 1;
            for (int p = idx - 1, q = k; p >= 0 && q > 0; p--, q--) {
                dp[idx] = std::max(dp[idx], 1 + dp[p]);
            }
            for (int p = idx + 1, q = k; p < 26 && q > 0; p++, q--) {
                dp[idx] = std::max(dp[idx], 1 + dp[p]);
            }
        }

        return *(std::max_element(dp.begin(), dp.end()));
    }
};
