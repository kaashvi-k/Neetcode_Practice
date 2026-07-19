class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int tester = nums.size(); 

        for(int i = 0 ; i < nums.size() ; i++){
            tester ^= i;
        }

        for(int i = 0 ; i < nums.size() ; i++ ){
            tester ^= nums[i];
        }

        return tester;
        
    }
};
