class Solution {
public:
    vector<string> res ;
    
    void backtrack(int openN, int closedN, int n,  string& stck){
        if(openN == closedN && openN == n){
            res.push_back(stck);
            return; 
        }

        if(openN < n){
            stck += '(' ; 
            backtrack(openN + 1, closedN, n, stck);
            stck.pop_back();
        }

        if(closedN < openN){
            stck += ')';
            backtrack(openN, closedN+1, n, stck);
            stck.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string stck; 
        backtrack(0, 0, n, stck);
        return res; 
    }
};
