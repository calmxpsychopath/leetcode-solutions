class Solution {
private:
    int row, col, z, sz, ans;
    std::vector<int> dx = {-1, 1, 0, 0};
    std::vector<int> dy = {0, 0, 1, -1};
    std::unordered_set<int> st;
    std::unordered_map<int, int> mp;

public:
    int largestIsland(std::vector<std::vector<int>>& grid) {
        row = grid.size(); col = grid[0].size();

        auto dfs = [&](int i, int j, auto&& dfs) -> void {
            sz += 1;
            grid[i][j] = z;

            for(int k = 0; k < 4; k++) {
                int tx = i + dx[k];
                int ty = j + dy[k];

                if(tx >= 0 && tx < row && ty >= 0 && ty < col && grid[tx][ty] == 1) {
                    dfs(tx, ty, dfs);
                }
            }
        };

        mp[0] = 0; ans = 0; z = -1;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    sz = 0;
                    dfs(i, j, dfs);
                    mp[z] = sz;
                    ans = std::max(ans, mp[z]);
                    --z;
                }
            }
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 0) {
                    if(i + 1 < row) st.insert(grid[i + 1][j]);
                    if(i - 1 >= 0)  st.insert(grid[i - 1][j]);
                    if(j + 1 < col) st.insert(grid[i][j + 1]);
                    if(j - 1 >= 0)  st.insert(grid[i][j - 1]);

                    int tmp = 1;
                    for(auto itr = st.begin(); itr != st.end(); itr++)
                        tmp += mp[*itr];

                    ans = std::max(ans, tmp);
                    st.clear();
                }
            }
        }

        return ans;
    }
};
