class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adjList(n);
        for (auto it : edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            if(x == destination) {
                return true;
            }

            for (int n : adjList[x]) {
                if (!visited[n]) {
                    q.push(n);
                    visited[n] = true;
                }
            }
        }
        return false;
    }
};