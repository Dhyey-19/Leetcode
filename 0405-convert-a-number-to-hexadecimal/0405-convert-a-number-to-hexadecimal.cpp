class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        unsigned int n = num;
        string digits = "0123456789abcdef";
        string hex = "";    
        while(n > 0) {
            int rem = n % 16;
            hex += digits[rem];
            n /= 16;
        }

        reverse(hex.begin(), hex.end());
        return hex;
    }
};