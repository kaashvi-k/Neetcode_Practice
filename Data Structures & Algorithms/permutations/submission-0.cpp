class Solution {
public:
    vector<int> numcopy; 
    vector<vector<int>> result; 
    vector<int> seq; 
    vector<int> indexes;

    void backtracking(vector<int> seq, vector<int> indexes){
        if(seq.size() == numcopy.size()){
            result.push_back(seq);
            return;
        }

        for(int j = 0 ; j < numcopy.size(); j++){
            if(find(indexes.begin(), indexes.end() , j) != indexes.end()){
                continue; 
            }

            seq.push_back(numcopy[j]);
            indexes.push_back(j);

            backtracking(seq, indexes);
            seq.pop_back();
            indexes.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        numcopy = nums; 
        
        backtracking({}, {});

        return result; 
    }
};
