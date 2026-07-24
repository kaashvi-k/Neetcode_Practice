class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        bool rowZero = false; 

        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size(); j ++){

                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0; 

                    if(i > 0) matrix[i][0] = 0; 
                    else rowZero = true; 
                }
            }
        }


        for(int r = 1 ; r < matrix.size(); r++){
            for(int c = 1; c < matrix[0].size(); c++){

                if(matrix[0][c] == 0 || matrix[r][0] == 0) matrix[r][c] = 0; 

                
            }
        }

        if(matrix[0][0] == 0) {
            for(int i = 0 ; i < matrix.size(); i++) {
                matrix[i][0] = 0; 
            }
        }

        if (rowZero) {

            for(int i = 0 ; i < matrix[0].size(); i++){
                matrix[0][i] = 0; 
            }
        }
        
    }
};
