class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) return false;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    bool isPrimeBits(int n) {
        int bits = 0;
        while(n) {
            if(n & 1) bits++;
            n = n >> 1;
        }
        return isPrime(bits);
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++) {
            if(isPrimeBits(i)) cnt++;
        }    
        return cnt;
    }
};