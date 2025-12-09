class Solution {
public:
    int totalMoney(int n) {
        int w = n / 7;       // full weeks
        int r = n % 7;       // extra days

        // Sum of full weeks
        int full = 7 * w * (w + 1) / 2 + 21 * w;

        // Sum of remaining days
        int rem = r * (2 * (w + 1) + (r - 1)) / 2;

        return full + rem;
    }
};
