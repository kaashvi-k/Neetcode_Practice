class Solution {
public:

    bool backtracking(vector<int> & nums, int target, int currIdx, int currSum){ 

        if(currSum > target) return false; 
        if(currIdx == nums.size()) return (currSum == target);

        cout << currSum  << endl; 

        return backtracking(nums, target, currIdx + 1, currSum + nums[currIdx]) || 
                backtracking(nums, target, currIdx + 1, currSum);
    }
    bool canPartition(vector<int>& nums) {

        int sum = 0; 


        for(int num : nums){
            sum += num; 
        }

        if(sum%2 != 0) return false ; 
        
        int target = sum/2; 

        return backtracking(nums, target, 0 , 0);

        

        
    }
};
