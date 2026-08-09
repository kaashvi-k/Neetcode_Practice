class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int N = grid.size(); 
        set<pair<int, int>> visit; 

        priority_queue<vector<int> , vector<vector<int>>, greater<>> minHeap; 

        vector<vector<int>> directions = { {0, 1} , {0, -1} , {1, 0} , {-1, 0}}; 

        minHeap.push({grid[0][0], 0 , 0}); 
        visit.insert({0, 0});


        while(!minHeap.empty()){

            auto curr = minHeap.top(); 
            minHeap.pop(); 

            int t = curr[0] , r = curr[1], c = curr[2]; 

            if(r == N-1 && c == N - 1) return t; 

            for(const auto&dir : directions){

                int nr = r + dir[0] ; 
                int nc = c + dir[1]; 

                if(nr < 0 || nr == N || nc < 0 || nc == N || visit.count({nr, nc})) continue; 

                visit.insert( {nr, nc}); 
                minHeap.push({ max(t, grid[nr][nc]) , nr, nc}); 
            }
        }


        return N*N ; 
        
    }
};
