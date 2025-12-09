class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> right;
        unordered_map<int, long long> left;

        // initially all freq in right map
        for (int x : nums) right[x]++;

        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            int mid = nums[j];
            right[mid]--;  // mid moves from right to left

            long long target = mid * 2;

            // count i < j and k > j
            long long cnt_i = left[target];
            long long cnt_k = right[target];

            ans = (ans + (cnt_i * cnt_k) % MOD) % MOD;

            left[mid]++;  // mark mid as processed in left side
        }

        return ans;
    }
};
