class Solution {
private:
    int row, col;
    std::vector<int> config;
    std::vector<std::vector<int>> dp;

public:
    int maxStudents(vector<vector<char>>& seats) {
        row = seats.size(); col = seats[0].size();   
        
        config.resize(row + 1);
        for(int i = 0; i < row; i++) {
            int curr = 0;
            for(int j = col - 1; j >= 0; j--) {
                curr = curr * 2 + (seats[i][j] == '.');
            }
            config[i + 1] = curr;
        }
		
        dp.resize(row + 1);
        std::fill(dp.begin(), dp.end(), vector<int>(1 << col, -1));
		
        dp[0][0] = 0;
        for(int i = 1; i <= row; i++) {
            int valid = config[i];

            for(int curr = 0; curr < (1 << col); curr++) {
                bool sub = ((curr & valid) == curr);
                bool adj = ((curr & (curr >> 1)) == 0);

                if(sub && adj) {
                    for(int prev = 0; prev < (1 << col); prev++) {
                        bool lhs = (((prev >> 1) & curr) == 0);
                        bool rhs = (((prev << 1) & curr) == 0);

                        if(lhs && rhs && dp[i - 1][prev] != -1) {
                            dp[i][curr] = std::max(dp[i][curr], 
                                                   dp[i - 1][prev] + __builtin_popcount(curr));
                        }
                    }
                }
            }
        }
        
        return *std::max_element(dp[row].begin(), dp[row].end());
    }
};
