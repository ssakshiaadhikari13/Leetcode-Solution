class Solution {
public:

    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int src, int dest) {
        
        if(src == dest)
            return true;

        visited[src] = true;

        for(int neighbor : adj[src]) {
            if(!visited[neighbor]) {
                if(dfs(adj, visited, neighbor, dest))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);

        return dfs(adj, visited, source, destination);
    }
};
