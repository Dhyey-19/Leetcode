class Solution {
public:
    void dfsHelper(vector<vector<int>>& paths, vector<vector<int>>& graph,
                   int src, int dest, vector<int>& path) {
        path.push_back(src);
        if (src == dest) {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        for (int v : graph[src]) {
            dfsHelper(paths, graph, v, dest, path);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        int n = graph.size() - 1;
        vector<int> path;
        dfsHelper(paths, graph, 0, n, path);
        return paths;
    }
};