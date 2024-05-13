class Solution {
    using i64 = long long;

private:
    i64 sum, cnt;
    int freq[1024] = {0};

public:
    i64 wonderfulSubstrings(std::string word) {
        sum = cnt = 0;
        freq[0] = 1;

        for(const char& ch: word) {
            int bit = ch - 'a';

            sum ^= (1 << bit);
            cnt += freq[sum];
            freq[sum] += 1;

            for(int i = 0; i < 10; i++) {
                cnt += freq[sum ^ (1 << i)];
            }
        }

        return cnt;
    }
};
