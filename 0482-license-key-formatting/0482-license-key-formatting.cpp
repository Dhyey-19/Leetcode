class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str = "";
        for(char ch : s) {
            if(ch == '-') {
                continue;
            } 
            if(isdigit(ch)){
                str += ch;
            } else {
                str += toupper(ch);
            }
        }
        string ans = "";
        int len = str.length();
        for(int i = len - 1; i >= 0; i-=k) {
            int j = i, cnt = k;
            while(j >= 0 && cnt--) {
                ans += str[j--];
            }
            ans += '-';
        }
        if(!ans.empty()) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};