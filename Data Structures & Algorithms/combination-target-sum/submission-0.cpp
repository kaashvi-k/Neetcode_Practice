class Solution {
public:
    vector<vector<int>> res; 
    int targetSum;
    vector<int> numarr;  
    void dfs(int i , vector<int> currList, int tot){

        if(tot == targetSum){
            res.push_back(currList); 
            return ; 
        }

        if(i >= numarr.size() || tot > targetSum) return ; 

        //case 1 
        currList.push_back(numarr[i]);
        dfs(i, currList, tot + numarr[i]);
        currList.pop_back();

        dfs(i+1 , currList, tot);


        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        targetSum = target;  
        numarr = nums; 

        dfs(0, {} , 0); 

        return res; 
    }
};
