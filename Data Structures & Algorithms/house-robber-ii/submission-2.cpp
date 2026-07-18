class Solution {
public:
    int solving(vector<int> nums){

        int n = nums.size();

        vector<int> money(n, 0);

        money[0] = nums[0];
        money[1] = max(nums[0], nums[1]);

        for(int i = 2 ; i < n ; i ++){
            money[i] = max( nums[i] + money[i-2], money[i-1]);
        }


        return money[n-1] ;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        return max(solving(vector<int>(nums.begin() + 1, nums.end())),
                        solving(vector<int>(nums.begin(), nums.end() - 1)));
        
    }
};
