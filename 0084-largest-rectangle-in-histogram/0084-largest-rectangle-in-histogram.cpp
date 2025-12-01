class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n), nsr(n);
        stack<int> stk;

        // Next Smaller Left
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) 
                stk.pop();

            nsl[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        // Next Smaller Right
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();

            nsr[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
