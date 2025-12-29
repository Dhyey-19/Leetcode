class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            long value = nums[i];
            if (value == first || value == second || value == third) continue;

            if (value > first) {
                third = second;
                second = first;
                first = value;
            } else if (value > second) {
                third = second;
                second = value;
            } else if (value > third) {
                third = value;
            }
        }

        return third == LONG_MIN ? first : third;
    }
};