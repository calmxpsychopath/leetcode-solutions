class Solution {
private: 
    int x1, x2, y1, y2;

    void find2min(std::vector<std::vector<int>>& grid, int r, int n) {
        if(grid[r][0] <= grid[r][1]) {
            x1 = grid[r][0], y1 = 0;
            x2 = grid[r][1], y2 = 1;
        }
        else {
            x1 = grid[r][1], y1 = 1;
            x2 = grid[r][0], y2 = 0;
        }

        for(int j = 2; j < n; j++) {
            if(grid[r][j] < x1) {
                x2 = x1, y2 = y1;
                x1 = grid[r][j], y1 = j;
            }
            else if(grid[r][j] < x2) {
                x2 = grid[r][j], y2 = j;
            }
        }
    }

    void fallpath(std::vector<std::vector<int>>& grid, int r, int n) {
        for(int j = 0; j < n; j++) {
            if(j != y1) grid[r][j] += x1;
            else grid[r][j] += x2; 
        }
    }

public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid[0][0];

        for(int i = 1; i < n; i++) {
            find2min(grid, i - 1, n);
            fallpath(grid, i, n);
        }

        return *(std::min_element(grid[n - 1].begin(), grid[n - 1].end()));
    }
};
