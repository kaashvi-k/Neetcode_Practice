class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = INT_MIN; 
        int sumcont = 0; 
        int sumcurr = 0; 
        for(int i = 0 ; i < nums.size(); i++){

            sumcont = sumcurr + nums[i];

            if(sumcont < nums[i]){
                sumcurr = nums[i] ; 
            }

            else sumcurr = sumcont; 

            sum = max(sumcurr, sum);

        }


        return sum;
    }
};
