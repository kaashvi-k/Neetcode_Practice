class Solution {
public:

    int ways = 0; 

    void recur(vector<int> & nums, int target, int currIdx){
        
        if(currIdx == nums.size()){
            if(target == 0) ways ++;
            return; 
        }

            recur(nums, target + nums[currIdx], currIdx + 1) ; 
            recur(nums, target - nums[currIdx] , currIdx + 1) ; 
    

        


    }
    int findTargetSumWays(vector<int>& nums, int target) {


        recur(nums, target, 0); 
        return ways; 
        
    }
};
