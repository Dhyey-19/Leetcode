class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Brute Force
        
        // int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     int leftSum = 0, rightSum = 0;
        //     for(int j = 0; j < i; j++) {
        //         leftSum += nums[j];
        //     }
        //     for(int k = i + 1; k < n; k++) {
        //         rightSum += nums[k];
        //     }
        //     if(leftSum == rightSum) {
        //         return i;
        //     }
        // }    
        // return -1;

        // Optimal
        int totalSum = 0;
        for(int num : nums) {
            totalSum += num;
        }
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            if(currSum == totalSum - currSum - nums[i]) {
                return i;
            }
            currSum += nums[i];
        }
        return -1;
    }
};