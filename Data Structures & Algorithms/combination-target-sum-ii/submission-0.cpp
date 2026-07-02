class Solution {
public:
    vector<int> candicopy; 
    int t; 
    vector<vector<int>> result; 

    void dfs(int sum, int i, vector<int> seq){
        if(sum == t){
            result.push_back(seq);
            return ;
        }

        if(sum > t || i >= candicopy.size()){
            return ; 
        }

        for(int j = i ; j < candicopy.size() ; j++){
            if(j > i && candicopy[j] == candicopy[j-1]){
                continue; 
            }

            sum += candicopy[j];
            seq.push_back(candicopy[j]);
            dfs(sum, j+1, seq);
            sum-= candicopy[j];
            seq.pop_back();
        }

        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       candicopy = candidates; 
       t = target;

       sort(candicopy.begin() , candicopy.end());
       dfs(0, 0, {}); 
       return result;
    }
};
