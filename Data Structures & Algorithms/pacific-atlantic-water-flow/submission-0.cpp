/*
for each cell do dfs
add only to queue if the adjacent cell has equal or lower height 
see if you can reach both the pacific and atlantic ocean 
you will reach the pacific ocean of the cell has row 0 or column 0
you will reach atlantic if the cell has last row or last column
keep bool for both 
*/

class Solution {
public:

    vector<int> ro = {1, -1, 0 , 0};
    vector<int> co = {0, 0, -1, 1};
    vector<vector<int>> visited ; 
 
    bool dfs(vector<vector<int>>& heights, int r, int c){
        
        bool pacific = 0, atlantic = 0;

        stack<pair<int, int>> st; 

        st.push({r, c});
        visited[r][c] = -1; 

        while(!st.empty()){

            int rc = st.top().first; 
            int cc = st.top().second; 
            if(rc == 0 || cc == 0 ) pacific = 1; 
            if(cc == heights[0].size()-1 || rc == heights.size() -1) atlantic = 1;
            if(pacific && atlantic) return true; 
            st.pop();

            for(int i = 0; i < 4 ; i++){
                int rn = rc + ro[i];
                int cn = cc + co[i];

                 

                

                if(rn >= 0 && rn < heights.size() &&
                    cn >= 0 && cn < heights[0].size() && visited[rn][cn] != -1
                    && heights[rn][cn] <= heights[rc][cc]){

                        visited[rn][cn] = -1; 
                        st.push({rn,cn});

                }
            }

            
        }

        return(pacific&&atlantic);


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         
        
        vector<vector<int>> ans = {}; 
        
        for(int i = 0 ; i < heights.size(); i++){
            for(int j = 0 ; j < heights[0].size() ; j++){
                visited = heights;
                if(dfs(heights, i , j)){
                    ans.push_back({i,j});
                }
            }
        }

        return ans; 
    }
};
