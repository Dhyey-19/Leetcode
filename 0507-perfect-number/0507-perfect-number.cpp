class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> factors;
        for(int i = 1; i < num; i++) {
            if(num % i == 0) {
                factors.push_back(i);
            }
        }
        if(accumulate(factors.begin(), factors.end(), 0) == num) {
            return true;
        } else {
            return false;
        }
    }
};