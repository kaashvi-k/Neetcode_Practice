class Solution {
public:

    unordered_set<int> visited; 
    int SumofSquares(int n){

        if(n == 0) return 0; 

        int div = 10; 
        int sos = 0; 


        while(n){
            int digit = n%div; 
            n = n/div;
            sos += digit*digit; 
        }


        return sos; 

    }
    
    bool isHappy(int n) {


        if(SumofSquares(n) == 1) return true; 

        while(SumofSquares(n) != 1){
            if( visited.find(SumofSquares(n)) != visited.end()) return false; 

            n = SumofSquares(n) ; 
            visited.insert(n);
        }


        return true; 

    }
};
