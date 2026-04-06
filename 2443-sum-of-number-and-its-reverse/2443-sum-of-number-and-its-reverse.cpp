class Solution {
public:
    int rev(int n) {
        int r = 0;
        while(n > 0) {
            int last = n % 10;
            r = r * 10 + last;
            n = n / 10;
        }
        return r;
    }

    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++) {
            int sum = i + rev(i);
            if(sum == num) {
                return true;
            }
        }    
        return false;
    }
};