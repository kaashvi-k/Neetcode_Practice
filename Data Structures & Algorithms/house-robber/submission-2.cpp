class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> money(n, 0);

        if(n == 1) return nums[0];
        if(n == 0)return 0;
        
        money[0] = nums[0];
        money[1] = max( money[0], nums[1]);

        for(int i = 2; i < n; i++){
            money[i] = max( nums[i] + money[i-2] , money[i-1]) ;
        }


        return money[n-1];
        
    }
};
