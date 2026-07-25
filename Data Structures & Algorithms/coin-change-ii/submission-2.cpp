class Solution {
public:
    int ways = 0; 

    
    
    int recur(vector<int>& coins, int target, int curIndex, vector<vector<int>>& memo){
        if(target == 0) return 1;

        if(target < 0 || curIndex == coins.size()) return 0; 

        if(memo[target][curIndex] != 0) return memo[target][curIndex] ;

        for(int i = curIndex ; i < coins.size(); i ++){
            
            if(target - coins[i] >= 0) memo[target][curIndex] += recur(coins, target- coins[i], i, memo);
        }


        return memo[target][curIndex];

    }
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> memo(amount + 1, vector<int> (coins.size() + 1 , 0));

        return recur(coins, amount, 0, memo); 

 
        
    }
};
