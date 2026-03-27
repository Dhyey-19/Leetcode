class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int shifts = k % n;

        vector<vector<int>> temp = mat;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i % 2 == 0) {
                    // even row → left shift
                    if(mat[i][j] != temp[i][(j + shifts) % n]) 
                        return false;
                } else {
                    // odd row → right shift
                    if(mat[i][j] != temp[i][(j - shifts + n) % n]) 
                        return false;
                }
            }
        }
        return true;
    }
};