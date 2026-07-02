class Solution {
public:
    vector<int> numcopy; 
    vector<vector<int>> result; 


    void backtracking(vector<int> seq, vector<bool> &used){
        if(seq.size() == numcopy.size()){
            result.push_back(seq);
            return;
        }

        for(int j = 0 ; j < numcopy.size(); j++){
            if(used[j]){
                continue; 
            }

            seq.push_back(numcopy[j]);
            used[j] = true; 

            backtracking(seq, used);
            seq.pop_back();
            used[j] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        numcopy = nums; 
        vector<bool> used(nums.size(), false);
        
        backtracking({}, used);

        return result; 
    }
};
