class Solution {
public:
bool ispalindrome(string y,int l,int r)
{
    while(l<r)
    {
        if(y[l]!=y[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else
            {
                return ispalindrome(s,left+1,right) || ispalindrome(s,left,right-1);
            }
        }
        return true;
        
    }
};