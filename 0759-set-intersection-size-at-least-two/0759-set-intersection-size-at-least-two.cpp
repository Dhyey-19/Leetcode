class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // Step 1: Sort intervals by increasing end.
        // If ends are same, sort start in decreasing order.
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) 
                return a[0] > b[0];     // start decreasing when end same
            return a[1] < b[1];
        });

        int result = 0;

        // last1 = largest picked number
        // last2 = second largest picked number
        int last1 = -1, last2 = -1;

        for (auto &in : intervals) {
            int l = in[0], r = in[1];

            bool last1_in = (last1 >= l && last1 <= r);
            bool last2_in = (last2 >= l && last2 <= r);

            // Case 1 → both already inside → do nothing
            if (last1_in && last2_in) {
                continue;
            }

            // Case 2 → only one is inside → add 1 new number (r)
            if (last1_in) {
                result += 1;
                last2 = last1;
                last1 = r;
            }
            else {
                // neither inside → pick two numbers r-1 and r
                result += 2;
                last2 = r - 1;
                last1 = r;
            }
        }

        return result;
    }
};
