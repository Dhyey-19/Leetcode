class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int a : arr) {
            freq[a]++;
            if(freq[a] > ceil(arr.size() / 4)) {
                return a;
            }
        }
        return -1;
    }
};