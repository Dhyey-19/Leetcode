class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool FirstRowZero = false;
        bool FirstColZero = false;

        // Step 1: Check if first column has any zeros
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                FirstColZero = true;
            }
        }

        // Step 2: Check if first row has any zeros
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                FirstRowZero = true;
            }
        }

        // Step 3: Mark zeros in first row and column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Set zeros based on markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Handle first row
        if (FirstRowZero) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 6: Handle first column
        if (FirstColZero) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
