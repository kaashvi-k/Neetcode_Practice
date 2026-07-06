class Solution {
public:
    int area = 0; 
    vector<int> ro = {1 , 0 , 0 , -1} ;
    vector<int> co = {0 , +1 , -1, 0} ;

    int dfs( vector<vector<int>> & grid, int r , int c){

        queue<pair<int, int>> q; 

        q.push( {r,c}) ;
        grid[r][c] = 0;
        int count = 0; 

        while( !q.empty() ){
            count ++;

            int rc = q.front().first ; 
            int cc = q.front().second;

            

            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int rn = rc + ro[i];
                int cn = cc + co[i];

                if(rn >= 0 && rn < grid.size() && cn >= 0 && cn < grid[0].size()
                    && grid[rn][cn] == 1){
                        grid[rn][cn] = 0 ;
                        q.push( {rn , cn});
                    }
            }
        }


        return count; 


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] == 1) {
                    area = max( dfs(grid, i , j) , area);
                }
            }
        }

        return area; 
        
    }
};
