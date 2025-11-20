class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int idx = 0;
        for(int i = 1; i <= n; i++) {
            if(idx == target.size()) {
                break;
            }
            ops.push_back("Push");
            if(i == target[idx]) {
                idx++;
            } else {
                ops.push_back("Pop");
            }
        }    
        return ops;
    }
};