class Solution {
public:

    bool dfs(int node , int parent, vector<vector<int>> &adj, vector<int>& visited){

        if(visited[node]) return true; 

        visited[node] = true; 

        for(int nei : adj[node]){
            if(nei == parent) continue; 
            if(dfs(nei, node, adj, visited)) return true; 
        }

        return false; 
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> adj(n+1);

        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            vector<int> visited(n+1, 0);
            if( dfs(e[0], -1 , adj, visited)){
                return {e[0], e[1]} ;
            }
        }


        return {};
        
    }
};
