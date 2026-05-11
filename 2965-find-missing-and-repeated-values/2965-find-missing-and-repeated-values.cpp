class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long N = n * n;

        long long expectedSum = N * (N + 1) / 2;
        long long expectedSqSum = N * (N + 1) * (2 * N + 1) / 6;

        long long actualSum = 0;
        long long actualSqSum = 0;

        for (auto &row : grid) {
            for (int num : row) {
                actualSum += num;
                actualSqSum += 1LL * num * num;
            }
        }

        long long diff = actualSum - expectedSum; 
        // x - y

        long long sqDiff = actualSqSum - expectedSqSum; 
        // x² - y²

        long long sum = sqDiff / diff; 
        // x + y

        int repeated = (diff + sum) / 2;
        int missing = sum - repeated;

        return {repeated, missing};
    }
};