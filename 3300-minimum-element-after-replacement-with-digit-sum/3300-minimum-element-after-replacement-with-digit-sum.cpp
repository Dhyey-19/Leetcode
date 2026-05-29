class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int digitSum = 0;
            while(num > 0) {
                digitSum += num % 10;
                num = num / 10;
            }
            nums[i] = digitSum;
        }
        return *min_element(nums.begin(), nums.end());
    }
};