class Solution {
public:
    // bool isPrime(int n) {
    //     if (n < 2) return false;
    //     for (int i = 2; i * i <= n; i++) {
    //         if (n % i == 0) return false;
    //     }
    //     return true;
    // }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int sum = 0;
            int cnt = 0;

            for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int d1 = i;
                    int d2 = x / i;

                    if (d1 == d2) {
                        cnt += 1;
                        sum += d1;
                    } else {
                        cnt += 2;
                        sum += d1 + d2;
                    }
                }

                if (cnt > 4) break;
            }

            if (cnt == 4) ans += sum;
        }

        return ans;
    }
};
