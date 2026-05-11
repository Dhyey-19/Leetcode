class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> freq;
        int n = grid.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }

        int repeated = -1, missing = -1;

        for(int num = 1; num <= n * n; num++) {
            if(freq[num] == 2)
                repeated = num;

            if(freq[num] == 0)
                missing = num;
        }

        return {repeated, missing};
    }
};