class Solution {
public:
    int addDigits(int num) {
        // Brute Force
        
        // int sum;
        // while (num >= 10) {
        //     sum = 0;
        //     while (num > 0) {
        //         sum += num % 10;
        //         num = num / 10;
        //     }
        //     num = sum;
        // }
        // return sum;

        // Optimal
        if(num == 0) return 0;
        else if(num % 9 == 0) return 9;
        else return num % 9;
    }
};