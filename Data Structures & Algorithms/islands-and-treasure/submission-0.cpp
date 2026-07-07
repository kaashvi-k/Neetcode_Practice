class Solution {
public:
    vector<vector<int>> visited;
    queue<pair<int,int>> q;

    void addRoom(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || r == grid.size() || 
            c < 0 || c == grid[0].size() || visited[r][c] == 3 ||
            grid[r][c] == -1
            ) return ; 
        
        visited[r][c] = 3;
        q.push({r,c});

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        visited = grid; 

        

        for(int i = 0 ; i < grid.size() ; i ++){
            for( int j =0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = 3;
                }
            }
        }

        int dist = 0; 
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                grid[r][c] = dist;
                addRoom(r+1 ,c , grid);
                addRoom(r-1, c, grid);
                addRoom(r, c+1 , grid);
                addRoom(r, c-1, grid);
            }

            dist ++;
        }
    }
};
