class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prevOne = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(prevOne != -1) {
                    if(i - prevOne - 1 < k) {
                        return false;
                    }
                }
                prevOne = i;
            }
        }
        return true;
    }
};