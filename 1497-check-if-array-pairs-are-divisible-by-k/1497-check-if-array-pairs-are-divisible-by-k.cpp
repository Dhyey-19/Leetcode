class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> freq;

        for(int num : arr) {
            int rem = ((num % k) + k) % k;
            freq[rem]++;
        }

        if(freq[0] % 2 != 0)
            return false;

        for(int r = 1; r < k; r++) {
            if(r == k - r) {
                if(freq[r] % 2 != 0)
                    return false;
            }
            else {
                if(freq[r] != freq[k-r])
                    return false;
            }
        }

        return true;
    }
};