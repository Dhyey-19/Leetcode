class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // if(mat.size() * mat[0].size() != r * c) {
        //     return mat;
        // }
        // vector<vector<int>> res(r, vector<int>(c));
        // int row = 0, col = 0;
        // for(int i = 0; i < mat.size(); i++) {
        //     for(int j = 0; j < mat[0].size(); j++) {
        //         if(col == c) {
        //             row++;
        //             col = 0;
        //         }
        //         res[row][col++] = mat[i][j];
        //     }
        // }
        // return res;

        // Optimal
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < m * n; i++) {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        return res;
    }
};