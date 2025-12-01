class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int, int> freq;
        // for(int num : nums) {
        //     freq[num]++;
        // }
        // for(auto& [num, f] : freq) {
        //     if(f > 1) {
        //         return true;
        //     }
        // }
        // return false;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};