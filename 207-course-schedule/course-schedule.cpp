class Solution {
public:

    bool dfs(vector<vector<int>>& p, int node, vector<int> &s, vector<int> &v){

        v[node] = 1;
        s[node] = 1;

        for(auto it: p[node]){
            if(!v[it]) 
                if(dfs(p, it, s, v)) return true;
            if(s[it]) return true;
        }
        s[node] = 0;
        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> indegree(numCourses, 0);

        

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i]) indegree[it]++;
        }

        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return topo.size()==numCourses;

    }
};