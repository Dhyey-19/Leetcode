class Solution {
public:

    int manhattan(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<bool> visited(n, false);
        pq.push({0, 0}); // {cost, node}

        int cost = 0;
        int edgesUsed = 0;

        while(edgesUsed < n) {
            auto [wt, u] = pq.top();
            pq.pop();
            if(visited[u])
                continue;

            visited[u] = true;
            cost += wt;
            edgesUsed++;

            // Add all neighbors
            for(int v = 0; v < n; v++) {
                if(!visited[v]) {
                    int dist = manhattan(points[u], points[v]);
                    pq.push({dist, v});
                }
            }
        }

        return cost;
    }
};