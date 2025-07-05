class Solution {
public:

    bool dfs(vector<vector<int>>& edges, int source, int destination, vector<int>& visited){
        
        visited[source] = 1;


        for(auto nbr: edges[source]){
            if(!visited[nbr]){
                dfs(edges, nbr, destination, visited);
            }
        }
        return visited[destination];
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n);
        vector<vector<int>> adj(n);  // Build adjacency list

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return dfs(adj, source, destination, visited);


    }
};