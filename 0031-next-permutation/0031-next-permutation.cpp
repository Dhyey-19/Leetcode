class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for (int i = nums.size() - 2; i >= 0; i--) { // Find the first decreasing element from end
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        if (index == -1) { // If no such index found - Reverse the entire array
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > index; i--) { // Find element just greater than nums[index]
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // Reverse the part after index
        reverse(nums.begin() + index + 1, nums.end());
    }
};