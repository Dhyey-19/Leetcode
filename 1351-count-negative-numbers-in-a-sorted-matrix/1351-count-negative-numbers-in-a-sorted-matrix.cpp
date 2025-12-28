class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Brute Force
        
        // int cnt = 0;
        // for(int i = 0; i < grid.size(); i++) {
        //     for(int j = grid[0].size() - 1; j >= 0; j--) {
        //         if(grid[i][j] < 0) cnt++;
        //     }
        // }
        // return cnt;

        int m = grid.size(), n = grid[0].size();
        int row = 0, col = n - 1, count = 0;
        while (row < m && col >= 0) {
            if (grid[row][col] < 0) {
                count += (m - row); // All numbers below are negative too
                col--;
            } else {
                row++;
            }
        }
        return count;
  
    }
};