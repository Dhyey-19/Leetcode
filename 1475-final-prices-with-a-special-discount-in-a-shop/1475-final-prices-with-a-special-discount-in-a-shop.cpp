class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> discount;
        for(int i = 0; i < prices.size(); i++) {
            bool x = false;
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] <= prices[i]) {
                    discount.push_back(prices[i] - prices[j]);
                    x = true;
                    break;
                }
            }
            if(x == false) {
                discount.push_back(prices[i]);
            }
        }    
        return discount;
    }
};