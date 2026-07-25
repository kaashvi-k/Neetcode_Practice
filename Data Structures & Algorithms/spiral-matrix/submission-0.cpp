class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res; 

        int toprow = 0, rightcol = matrix[0].size() -1 , botrow = matrix.size() - 1, leftcol = 0;


        while(leftcol <= rightcol && toprow <= botrow){

            for(int i = leftcol; i <= rightcol; i++){
                res.push_back(matrix[toprow][i]); 
            }

            toprow ++; 
            for(int i = toprow; i <= botrow; i++){
                res.push_back(matrix[i][rightcol]); 
                
            }

            rightcol --; 

            if(!(leftcol <= rightcol && toprow <= botrow)) break; 


            for(int i = rightcol; i >= leftcol ; i --){
                res.push_back(matrix[botrow][i]);
            }

            botrow --; 

            for(int i = botrow; i >= toprow ; i --){
                res.push_back(matrix[i][leftcol]); 
            }

            leftcol ++;
        }

        return res; 
        
    }
};
