class Solution {
public:

    bool dfs(vector<int>&nums, int curr, int target, vector<vector<int>>& dp){

        if(target == 0) return true; 
        if(curr == nums.size() || target < 0) return false; 

        if(dp[curr][target] != -1) return dp[curr][target];

        dp[curr][target] = dfs( nums, curr+1, target, dp) || dfs(nums, curr +1, target - nums[curr], dp);

        return dp[curr][target];
 
    }
    bool canPartition(vector<int>& nums) {

        int sum = 0; 


        for(int num : nums){
            sum += num; 
        }

        if(sum%2 != 0) return false ; 
        
        int target = sum/2; 

        vector<vector<int>> dp (nums.size() , vector<int> (target + 1, -1));

        return dfs(nums, 0, target , dp ); 

        

        
    }
};
