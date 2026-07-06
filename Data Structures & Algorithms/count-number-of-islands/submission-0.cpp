class Solution {
public:
    int count = 0;
    vector<int> ro = {-1 , 0 , 0 , 1 };
    vector<int> co = {0 , -1 , 1 , 0};

    void bfs(vector<vector<char>>& grid, queue<pair<int, int>> q ){
        while(!q.empty()){

            pair<int, int> curr = q.front();
            int r = curr.first; 
            int c = curr.second ; 
            q.pop();

            grid[curr.first][curr.second] = '.';

            for(int i = 0 ; i < 4; i++){
                
                int nr = r + ro[i];
                int nc = c + co[i];

                if (nr >= 0 && nr < grid.size() &&
                    nc >= 0 && nc < grid[0].size() &&
                    grid[nr][nc] == '1') {
                    q.push( { r+ro[i] , c+co[i] });
                }
            }
        }

        return ; 
    }


    int numIslands(vector<vector<char>>& grid) {
         

        for(int i = 0 ; i < grid.size() ; i++){
            for( int j = 0 ; j < grid[0].size() ; j ++){
                if(grid[i][j] == '1') {
                    queue<pair<int, int>> q;
                    count ++; 
                    q.push({i , j});
                    bfs(grid , q);
                }
            }
        }

        return count; 
    }
};
