class Solution {
private:

    // DFS cycle detection
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        // 1 = visiting
        state[node] = 1;
        for(int neighbour : adj[node]) {
            // Cycle found
            if(state[neighbour] == 1) {
                return true;
            }
            // Unvisited node
            if(state[neighbour] == 0 &&
               dfs(neighbour, adj, state)) {
                return true;
            }
        }
        // 2 = completely processed
        state[node] = 2;
        return false;
    }

    // Topological Sort DFS
    void topoSort(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        for(int neighbour : adj[node]) {
            if(!vis[neighbour]) {
                topoSort(neighbour, adj, vis, st);
            }
        }
        // Push after DFS
        st.push(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        // Build graph
        for(auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> state(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(state[i] == 0) {
                // If cycle exists,
                // topological ordering impossible
                if(dfs(i, adj, state)) {
                    return {};
                }
            }
        }

        // Topological Sort
        vector<bool> vis(numCourses, false);
        stack<int> st;
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Store answer
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};