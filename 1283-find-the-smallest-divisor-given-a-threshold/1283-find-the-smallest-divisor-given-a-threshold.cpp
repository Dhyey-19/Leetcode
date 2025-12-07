class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int th){
        int sm = 0;
        for (auto val : nums){
            sm += (val / mid);
            if(val % mid != 0) sm++;
            if (sm > th) return 0;
        }
        return sm <= th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (isPossible(mid, nums, threshold)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};