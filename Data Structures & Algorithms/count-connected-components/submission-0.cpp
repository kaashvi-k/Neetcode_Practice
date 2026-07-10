class Solution {
public:

    

    void dfs(int curr, vector<vector<int>>& adj, vector<int>& visited){

        stack<int> st; 
        st.push(curr);
        visited[curr] = 1; 

        while(!st.empty()){

            int current = st.top(); 
            st.pop();

            visited[current] = 1; 

            for(int nei : adj[current]){

                if(visited[nei]) continue ; 

                st.push(nei);
                visited[nei] = 1;

            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<int> visited(n, 0);

        vector<vector<int>> adj(n);

        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if(n == 0) return 0;
        dfs(0, adj, visited);
        int count = 1 ; 


        for(int i =0 ; i < n ; i++){
            if(!visited[i]) {
                dfs(i, adj , visited);
                count ++;
            }
        }


        return count; 

    }
};
