class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n : nums) {
            freq[n]++;
        }
        int f = 0;
        for(auto x : freq) {
            f = max(f, x.second);
        }
        int ans = INT_MAX;
        for(auto x : freq) {
            if(f == x.second) {
                int l = 0, r = nums.size() - 1;
                while(l < r + 1) {
                    if(nums[l] == x.first) {
                        break;
                    }
                    l++;
                }
                while(l < r) {
                    if(nums[r] == x.first) {
                        break;
                    }
                    r--;
                }
                ans = min(ans, r - l + 1);
            }
        }
        return ans;
    }
};