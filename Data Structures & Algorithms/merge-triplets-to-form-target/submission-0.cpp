class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<int> present(3, 0);
        vector<int> isTrue = {1, 1, 1};

        for( vector<int> trip : triplets){
            if(trip[0] > target[0] || trip[1] > target[1] || trip[2] > target[2]) continue; 

            else {
                if(trip[0] == target[0]) present[0] = 1; 
                if(trip[1] == target[1]) present[1] = 1; 
                if(trip[2] == target[2]) present[2] = 1; 
            }
        }


        return present == isTrue;
        
    }
};
