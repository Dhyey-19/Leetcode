class Solution {
public:
    void findCombination(int idx, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {
        // if all elements are processed, check if target is acheived. if yes, store ans
        if (idx == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // if curr ele is <= target, add it in ds
        if(arr[idx] <= target) {
            ds.push_back(arr[idx]);
            // recursive call for target - arr[idx] - to acheive the remaining target value
            findCombination(idx, target - arr[idx], arr, ans, ds);
            // backtrack
            ds.pop_back();
        }
        // if ele > target, skip it with recursive call of idx + 1
        findCombination(idx + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        findCombination(0, target, candidates, ans, vec);
        return ans;
    }
};