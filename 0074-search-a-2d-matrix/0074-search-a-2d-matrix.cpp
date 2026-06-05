class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto row : matrix) {
            if(target >= row.front() && target <= row.back()) {
                int low = 0;
                int high = row.size() - 1;
                while(low <= high) {
                    int mid = low + (high - low) / 2;
                    if(row[mid] == target) {
                        return true;
                    } else if(row[mid] < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};