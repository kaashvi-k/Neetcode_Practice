class Solution {
public:
    int helper(vector<int>&nums, int prv, int curr,  vector<vector<int>>& dp){

        if(curr == nums.size()) return 0;  

        int take = 0 ; 

        if(dp[prv+1][curr] != -1) return dp[prv+1][curr];

        if(prv == -1 || nums[prv] < nums[curr]){
            take = 1 + helper(nums, curr, curr+1, dp);
        }

        dp[prv+1][curr] = max(take, helper(nums, prv, curr+1, dp));

        return dp[prv+1][curr];
    }
    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>> dp (nums.size() + 1, vector<int> (nums.size() + 1 , -1));

        return helper(nums, -1, 0, dp);
        
    }
};
