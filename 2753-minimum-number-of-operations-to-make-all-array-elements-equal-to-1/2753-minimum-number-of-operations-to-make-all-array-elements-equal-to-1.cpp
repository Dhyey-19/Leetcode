class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int totalGCD = nums[0];
        for (int num : nums) totalGCD = gcd(totalGCD, num);
        
        // If GCD of entire array > 1 => impossible
        if (totalGCD > 1) return -1;
        
        // If any element is already 1
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;
        
        // Find smallest subarray with gcd == 1
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int currGCD = nums[i];
            for (int j = i; j < n; j++) {
                currGCD = gcd(currGCD, nums[j]);
                if (currGCD == 1) {
                    minLen = min(minLen, j - i + 1);
                    break; // No need to expand further
                }
            }
        }
        
        return (minLen - 1) + (n - 1);
    }
};
