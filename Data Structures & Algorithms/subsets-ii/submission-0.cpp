class Solution {
public:
    vector<vector<int>> result; 
    vector<int> numcopy;

    void backtracking(vector<int> seq, int i){
        if(i == numcopy.size()){
            return; 
        }



        for(int j = i ; j < numcopy.size(); j++){
            if(j > i && numcopy[j-1] == numcopy[j]){
                continue; 
            }

            seq.push_back(numcopy[j]);
            result.push_back(seq);
            backtracking(seq, j+1);
            seq.pop_back();


        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        numcopy = nums; 
        result.push_back({});
        backtracking({}, 0);
        return result;
    }
};
