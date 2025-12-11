class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> row, col;

        // store coordinates by row and column
        for (auto &b : buildings) {
            row[b[0]].push_back(b[1]);
            col[b[1]].push_back(b[0]);
        }

        // sort each row and column list
        for (auto &p : row) sort(p.second.begin(), p.second.end());
        for (auto &p : col) sort(p.second.begin(), p.second.end());

        int covered = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            // row[x] = sorted list of all y's on this row
            auto &r = row[x];
            auto itR = lower_bound(r.begin(), r.end(), y);
            int posR = itR - r.begin();

            bool left  = posR > 0;                 // exists y' < y
            bool right = posR + 1 < r.size();      // exists y' > y

            // col[y] = sorted list of all x's on this column
            auto &c = col[y];
            auto itC = lower_bound(c.begin(), c.end(), x);
            int posC = itC - c.begin();

            bool up   = posC > 0;                 // exists x' < x
            bool down = posC + 1 < c.size();      // exists x' > x

            if (left && right && up && down)
                covered++;
        }

        return covered;
    }
};
