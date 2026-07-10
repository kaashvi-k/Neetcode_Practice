class Solution {
public:
    bool dfs(int curr, int par, vector<vector<int>>& adj, vector<int>& visited){

        stack<pair<int, int>> st; 
        st.push({curr, par});
        visited[curr] = 1; 

        while(!st.empty()){
            int current = st.top().first; 
            int parent = st.top().second; 
            st.pop();

            visited[current] = 1; 

            for(int nei: adj[current]){
                if(nei == parent) continue ; 
                if(visited[nei] == true) return true; 

                visited[nei] = 1; 
                st.push({nei, current});
            }
        }

        return false; 


    }
    bool validTree(int n, vector<vector<int>>& edges) {

        bool ans = true; 

        vector<vector<int>> adj(n) ;
        vector<int> visited(n , 0);

        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ans = !dfs(0 , -1, adj, visited);
        
        for(int v: visited){
            if(!v) ans = false; 
        }

        return ans; 
    }
};
