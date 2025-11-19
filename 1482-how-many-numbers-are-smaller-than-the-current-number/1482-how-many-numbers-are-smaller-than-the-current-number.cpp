class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Brute Force
        
        // int n = nums.size();
        // vector<int> ans;
        // for(int num : nums) {
        //     int cnt = 0;
        //     for(int i = 0; i < n; i++) {
        //         if(nums[i] < num) {
        //             cnt++;
        //         }
        //     }
        //     ans.push_back(cnt);
        // }
        // return ans;

        // Optimal
        vector<int> freq(101, 0);   // frequency of each number
        
        // Count occurrences
        for (int num : nums) {
            freq[num]++;
        }
        
        // Prefix sum: freq[i] = how many numbers < i
        for (int i = 1; i < 101; i++) {
            freq[i] += freq[i - 1];
        }
        
        vector<int> ans;
        ans.reserve(nums.size());
        
        // Build answer
        for (int num : nums) {
            if (num == 0) ans.push_back(0);
            else ans.push_back(freq[num - 1]);
        }
        
        return ans;
    }
};