class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN, secondLargest = INT_MIN, idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (largest < nums[i]) {
                secondLargest = largest;
                largest = nums[i];
                idx = i;
            } else if (nums[i] < largest && nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }
        if (largest >= 2 * secondLargest) {
            return idx;
        } 
        return -1;
    }
};