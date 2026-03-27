class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        int degree = 0;
        for (int i : nums) degree = max(degree, ++count[i]);

        // Reset for the sliding window
        count.clear();
        int left = 0, min_len = nums.size();
        int current_max_freq = 0;

        for (int right = 0; right < nums.size(); right++) {
            count[nums[right]]++;
            
            while (count[nums[right]] == degree) {
                min_len = min(min_len, right - left + 1);
                count[nums[left]]--;
                left++;
            }
        }
        return min_len;
    }
};