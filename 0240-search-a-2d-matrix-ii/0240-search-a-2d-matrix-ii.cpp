class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // row size
        int n = matrix[0].size(); // col size
        int r = 0, c = n - 1; // starting from top-right corner
        while(r < m && c >= 0) {
            if(matrix[r][c] == target) {
                return true;
            } else if(matrix[r][c] > target) {
                c--; // moving left
            } else {
                r++; // moving down
            }
        }
        return false;
    }
};