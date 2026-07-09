class Solution {
public:

    queue<pair<int, int>> q; 
    int fresh = 0; 

    void addRoom(int r , int c , vector<vector<int>> & grid){
        if(r <  0|| r == grid.size() ||
            c < 0 || c == grid[0].size() ||
            grid[r][c] == -1 || grid[r][c] == 0 ) return;

        grid[r][c] = -1; 
        q.push({r, c});
        fresh--;
    }

    int orangesRotting(vector<vector<int>>& grid) {




        for(int i = 0; i < grid.size(); i++){
            for(int j =0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    grid[i][j] = -1;

                }

                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int time = 0 ; 

        while(!q.empty()){
            
            int siz = q.size();

            for(int i = 0 ; i < siz; i++){
                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                addRoom(r+1, c, grid);
                addRoom(r-1, c, grid);
                addRoom(r , c+1, grid);
                addRoom(r, c-1, grid);
            }

            if(!q.empty()) time ++;


        }

        if(fresh) return -1; 

        return time; 
    }
};
