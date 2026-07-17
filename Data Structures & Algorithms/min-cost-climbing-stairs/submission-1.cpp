class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> amounts (n+1 ,0);

        amounts[0] = 0;
        amounts[1] =  0;

        for(int i = 2; i <= n ; i ++){
            amounts[i] =  min(amounts[i-1]+cost[i-1] , amounts[i-2]+cost[i-2]);
        }


        return amounts[n];

    }
};
