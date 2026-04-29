class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size() && nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            i++;
            k--;
        }
        if(k % 2 == 1) {
            int minElementIdx = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minElementIdx] = -nums[minElementIdx];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};