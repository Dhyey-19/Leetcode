class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while(x > 0 || y > 0) {
            int remX = x % 2;
            int remY = y % 2;
            if(remX != remY) {
                res++;
            }
            x /= 2;
            y /= 2;
        }    
        return res;
    }
};