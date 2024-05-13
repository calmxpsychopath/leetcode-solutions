class Solution {
private:
    int row, col;
    int score;

public:
    int matrixScore(vector<vector<int>>& grid) {
        row = grid.size(); col = grid[0].size();

        for(int i = 0; i < row; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < col; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        score = row * (1 << (col - 1));
        for(int j = 1; j < col; j++) {
            int tmp = 0;
            for(int i = 0; i < row; i++) {
                tmp += (grid[i][j] == 1);
            }
            tmp = std::max(tmp, row - tmp);
            
            score += tmp * (1 << (col - j - 1));
        }

        return score;
    }
};
