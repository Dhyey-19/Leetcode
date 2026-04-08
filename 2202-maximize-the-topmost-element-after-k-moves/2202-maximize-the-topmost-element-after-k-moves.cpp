class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int mx = -1;
        int n = nums.size();
        for(int i = 0; i < n && k >= 0; i++) {
            if(((i > 0 || i < n - 1) && k > 1) || k % 2 == 0) {
                mx = max(mx, nums[i]);
            }
            k--;
        }     
        return mx;
    }
};