class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // because any fibonacci subarray of length <= 2 is always valid
        int cnt = 2, maxcnt = 2;
        if(nums.size() <= 2) return maxcnt;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] == nums[i-1] + nums[i-2]) {
                cnt++;
            } else {
                cnt = 2;
            }
            maxcnt = max(maxcnt, cnt);
        }
        return maxcnt;
    }
};