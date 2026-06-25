class Solution {
public:
    vector<int> path;
    vector<vector<int>> res ;


    void dfs(int i, vector<int>&  nums){
        if(i >= nums.size()) {
            res.push_back(path);
            return ;
        }

        //decision to include nums[i]
        path.push_back(nums[i]);
        dfs(i+1, nums);

        //decision to not include 
        path.pop_back();
        dfs(i+1, nums);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);

        return res;
    }
};
