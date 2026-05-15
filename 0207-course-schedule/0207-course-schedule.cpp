class Solution {
public:
    bool isCycle(int node,
                 vector<vector<int>>& adj,
                 vector<bool>& visited,
                 vector<bool>& recordPath) {

        visited[node] = true;
        recordPath[node] = true;

        for(int neighbour : adj[node]) {

            if(!visited[neighbour]) {

                if(isCycle(neighbour, adj, visited, recordPath)) {
                    return true;
                }

            }
            else if(recordPath[neighbour]) {
                return true;
            }
        }

        recordPath[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int V = numCourses;

        vector<vector<int>> adj(V);

        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(V, false);
        vector<bool> recordPath(V, false);

        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                if(isCycle(i, adj, visited, recordPath)) {
                    return false;
                }
            }
        }

        return true;
    }
};