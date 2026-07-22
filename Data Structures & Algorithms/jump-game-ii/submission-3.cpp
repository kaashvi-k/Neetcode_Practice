class Solution {
public:

    int recur(vector<int>& nums, int i, unordered_map<int, int>& memo){

        if(memo.count(i)) return memo[i];

        if(i == nums.size() - 1) return 0; 

        if(nums[i] == 0){
            return 20000000;
        }

        int res = 20000000;

        int end = min((int)nums.size(), i+ nums[i] + 1);

        for(int j = i + 1; j < end; j++){
            res = min(res, 1 + recur(nums, j, memo));
        }


        memo[i] = res; 
        return res; 
        
        

    }
    int jump(vector<int>& nums) {

        unordered_map<int, int> memo; 

        return recur(nums, 0, memo);
        
    }
};
