class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = size(g), p =size(s);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gi = 0, si = 0;
        while(gi<n && si<p){
            if(s[si]>=g[gi]){
                gi++;
            }
            si++;
        }
        return gi;
    }
};