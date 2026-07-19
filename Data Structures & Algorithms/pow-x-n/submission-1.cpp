class Solution {
public:
    double myPow(double x, int n) {
        
        double sol = 1.0 ; 

        x = (n > 0) ? x : 1/x;

        n = (n > 0) ? n : -n ; 

        while(n--){
            sol *= x; 
        }

        return sol;
    }
};
