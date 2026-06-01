class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int cases = 0;
        for(int num : nums) {
            int rightSum = total - leftSum - num;
            if(num == 0) {
                if(leftSum == rightSum) {
                    cases += 2;
                } else if(abs(leftSum - rightSum) == 1) {
                    cases++;
                }
            }
            leftSum += num;
        }    
        return cases;
    }
};