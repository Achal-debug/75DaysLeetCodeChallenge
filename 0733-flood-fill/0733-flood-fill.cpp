// Day 76 - 100 Days LeetCode Challenge
class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col,
             int originalColor, int newColor){
        int rows = image.size();
        int cols = image[0].size();
        if(row < 0 || row >= rows || col < 0 || col >= cols ||
           image[row][col] != originalColor){
            return;
        }
        image[row][col] = newColor;
        dfs(image, row + 1, col, originalColor, newColor);
        dfs(image, row - 1, col, originalColor, newColor);
        dfs(image, row, col + 1, originalColor, newColor);
        dfs(image, row, col - 1, originalColor, newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color){
            return image;
        }
        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};