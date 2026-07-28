class Solution {
public:
    vector<int> ro = {1, -1, 0, 0};
    vector<int> co = {0, 0, 1, -1};

    int recur(vector<vector<int>>& matrix, int r , int c, vector<vector<int>>& dp )
    {

      

        if(dp[r][c] != -1) return dp[r][c];

        dp[r][c] = 1; 

        for(int i = 0 ; i < 4; i ++){

            int rn = r + ro[i]; 
            int cn = c + co[i]; 

            if(rn < matrix.size() && rn >= 0 && cn < matrix[0].size() && cn >= 0
             && matrix[rn][cn] > matrix[r][c]){
                    dp[r][c]= max(dp[r][c], 1 + recur(matrix, rn, cn, dp));
                }

                
        }

        return dp[r][c];

        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int longest = 0; 
        vector<vector<int>> dp(matrix.size() , vector<int> (matrix[0].size(), -1));


        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                
                longest = max(longest, recur(matrix, i, j,  dp));
            }
        }
        

        return longest; 
    }
};
