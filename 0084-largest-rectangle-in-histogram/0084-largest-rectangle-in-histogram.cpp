class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // int n = heights.size();
        // vector<int> nsl(n), nsr(n);
        // stack<int> stk;

        // // Next Smaller Left
        // for (int i = 0; i < n; i++) {
        //     while (!stk.empty() && heights[stk.top()] >= heights[i]) 
        //         stk.pop();

        //     nsl[i] = stk.empty() ? -1 : stk.top();
        //     stk.push(i);
        // }

        // while (!stk.empty()) stk.pop();

        // // Next Smaller Right
        // for (int i = n - 1; i >= 0; i--) {
        //     while (!stk.empty() && heights[stk.top()] >= heights[i])
        //         stk.pop();

        //     nsr[i] = stk.empty() ? n : stk.top();
        //     stk.push(i);
        // }

        // int maxArea = 0;

        // for (int i = 0; i < n; i++) {
        //     int width = nsr[i] - nsl[i] - 1;
        //     int area = heights[i] * width;
        //     maxArea = max(maxArea, area);
        // }

        // return maxArea;

        // More Optimised
        
        int max_area = 0;
        vector<int> stk;
        heights.push_back(0);
        int n = heights.size();
        int height, width;

        for( int i=0; i < n; i++) {
            while(!stk.empty() && heights[stk.back()] > heights[i]) {
                height = heights[stk.back()]; stk.pop_back();
                if(stk.empty()) {
                    width = i;
                } else {
                    width = i - (stk.back() + 1);
                }
                max_area = max(max_area, height * width);
            }
            stk.push_back(i);
        }
        return max_area;
    }
};
