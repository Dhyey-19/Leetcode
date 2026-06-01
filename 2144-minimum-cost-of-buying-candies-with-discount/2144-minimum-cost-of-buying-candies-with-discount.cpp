class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size() <= 2) {
            return accumulate(cost.begin(), cost.end(), 0);
        }
        sort(cost.begin(), cost.end());
        int last = cost.size() - 1;
        int buy = 0, cst = 0;
        for(int i = last; i >= 0; i--) {
            if(buy == 2) {
                buy = 0;
                continue;
            }
            cst += cost[i];
            buy++;
        }
        return cst;
    }
};