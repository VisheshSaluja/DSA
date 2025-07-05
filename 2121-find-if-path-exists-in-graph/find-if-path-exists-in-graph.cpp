class Solution {
public:

    bool bfs(vector<vector<int>>& edges, int source, int destination, vector<int>& visited){
        queue<int> q;
        q.push(source);
        
        visited[source] = 1;


        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(auto nbr: edges[f]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push(nbr);
                }
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

        return bfs(adj, source, destination, visited);


    }
};