class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& state) {

        // Mark current node as VISITING
        // 0 = unvisited
        // 1 = visiting
        // 2 = completely visited
        state[node] = 1;

        for(int neighbour : adj[node]) {

            // If neighbour is already in current DFS path,
            // then cycle exists
            if(state[neighbour] == 1) {
                return true;
            }

            // If neighbour is unvisited,
            // perform DFS on it
            if(state[neighbour] == 0 &&
               dfs(neighbour, adj, state)) {
                return true;
            }
        }

        // Mark node as completely processed
        state[node] = 2;

        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        vector<int> state(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            // Start DFS only if node is unvisited
            if(state[i] == 0) {
                // If cycle found,
                // courses cannot be completed
                if(dfs(i, adj, state)) {
                    return false;
                }
            }
        }
        // No cycle found
        return true;
    }
};