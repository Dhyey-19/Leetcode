class Solution {
public: 
    int maxProfit(vector<int>& prices) {
        // Brute Force
        
        // int minstart = 0;
        // int maxend = 0;
        // int profit = 0;
        // for(int i = 0; i < prices.size()-1; i++) {
        //     for(int j = i+1; j < prices.size(); j++) {
        //         if(prices[j] > prices[i]) {
        //             profit = max(profit, prices[j] - prices[i]);
        //         }
        //     }
        // }
        // return profit;

        int maxProfit = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};