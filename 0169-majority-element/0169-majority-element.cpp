class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Approach: Moore Voting Algorithm
        int cnt = 0;
        int ele;
        for(int num : nums) {
            if(cnt == 0) {
                ele = num;
                cnt++;
                continue;
            }
            if(num == ele) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return ele;
    }
};
