class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        int currSum = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            currSum += nums[i];
            if(((sum - currSum) - currSum) % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};