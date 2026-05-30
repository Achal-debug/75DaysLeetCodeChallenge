// Day 80 - 100 Days LeetCode Challenge
class Solution {
public:
    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& visited,
             int row, int col,
             int prevHeight) {
        int rows = heights.size();
        int cols = heights[0].size();
        if(row < 0 || row >= rows ||
           col < 0 || col >= cols ||
           visited[row][col] ||
           heights[row][col] < prevHeight) {
            return;
        }
        visited[row][col] = true;
        dfs(heights, visited, row + 1, col, heights[row][col]);
        dfs(heights, visited, row - 1, col, heights[row][col]);
        dfs(heights, visited, row, col + 1, heights[row][col]);
        dfs(heights, visited, row, col - 1, heights[row][col]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++) {
            dfs(heights, pacific, i, 0, heights[i][0]);
            dfs(heights, atlantic, i, cols - 1, heights[i][cols - 1]);
        }
        for(int j = 0; j < cols; j++) {
            dfs(heights, pacific, 0, j, heights[0][j]);
            dfs(heights, atlantic, rows - 1, j, heights[rows - 1][j]);
        }
        vector<vector<int>> result;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};