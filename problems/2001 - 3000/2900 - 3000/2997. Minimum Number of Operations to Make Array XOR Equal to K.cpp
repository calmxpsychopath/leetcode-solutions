class Solution {
    using uint = unsigned int;
    
public:
    int minOperations(std::vector<int>& nums, int k) {
        int res = 0;
        for(const int& i: nums) {
            res ^= i;
        }
        res ^= k;

    //  return __builtin_popcount(res);
    /*  uint r = res; return std::popcount(r); */

        int ans = 0;
        while(res > 0) {
            ans += (res & 1);
            res = res >> 1;
        }
        return ans;
    }
};
