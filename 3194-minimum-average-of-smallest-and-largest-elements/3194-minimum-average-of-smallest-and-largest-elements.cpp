class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double minAvg = INT_MAX;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            double avg = (nums[i] + nums[j]) / 2.0;
            minAvg = min(minAvg, avg);
            i++;
            j--;
        }
        return minAvg;
    }
};