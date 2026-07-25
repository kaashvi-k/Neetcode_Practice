class Solution {
public:
    int maxRow , maxCol; 
    int paths = 0; 
    vector<int> ro = {0 , 1}; 
    vector<int> co = {1, 0};
    

    
    
    int recur(int r, int c, vector<vector<int>>& memo){

        if( r == maxRow && c == maxCol ) {
            return 1; 
        } 

        if(memo[r][c]) return memo[r][c];

        for(int i = 0; i < 2; i ++){
            int nr = r + ro[i]; 
            int nc = c + co[i];

            if(nr <= maxRow && nc <= maxCol ) {
                memo[r][c] += recur(nr, nc, memo);
            }
        }


        return memo[r][c];


        
    }
    int uniquePaths(int m, int n) {

        maxRow = m - 1; 
        maxCol = n - 1;  

        vector<vector<int>> memo(m + 1 , vector<int>(n+1, 0));

        return recur(0 , 0, memo);

        
    }
};
