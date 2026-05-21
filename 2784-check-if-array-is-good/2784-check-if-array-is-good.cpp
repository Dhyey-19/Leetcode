class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // last element should be n - 1
        if(nums[n - 1] != n - 1) {
            return false;
        }
        // n - 2 elements should be from 1 to n - 2
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] != i + 1) {
                return false;
            }
        }
        // last two elements should be same
        return nums[n - 1] == nums[n - 2];
    }
};