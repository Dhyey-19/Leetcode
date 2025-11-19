class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int num : nums) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] < num) {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};