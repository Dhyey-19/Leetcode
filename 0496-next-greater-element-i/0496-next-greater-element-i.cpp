class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size(), -1);
        stack<int> st;

        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                nge[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); ++i) {
            mp[nums2[i]] = nge[i];
        }

        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i) {
            result.push_back(mp[nums1[i]]);
        }
        return result;
    }
};