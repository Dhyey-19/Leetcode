class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            bool isChampion = true;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1) { // someone beats i
                    isChampion = false;
                    break;
                }
            }
            if (isChampion)
                return i;
        }

        return -1; // won't happen as per constraints
    }
};