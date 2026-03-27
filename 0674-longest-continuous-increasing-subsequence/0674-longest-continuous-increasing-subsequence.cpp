class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 1, maxCnt = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                cnt++;
            } else {
                maxCnt = max(maxCnt, cnt);
                cnt = 1;
            }
        }
        return max(maxCnt, cnt);
    }
};