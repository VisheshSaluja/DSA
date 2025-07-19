class Solution {
public:

    bool hasPath(int current, int target, unordered_map<int, vector<int>>& graph, unordered_set<int> &visited){
        if(current==target) return true;

        visited.insert(current);

        for(int neighbour: graph[current]){
            if(!visited.count(neighbour)){
                if(hasPath(neighbour, target, graph, visited)) return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> graph;
        

        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            if(graph.count(u) && graph.count(v)){
                unordered_set<int> visited;
                if(hasPath(u, v, graph, visited)){
                    return edge;
                }
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
        
    }
};