class Solution {
public:
    vector<vector<string>> result; 
    string sc;

    bool isPalindrome(string s, int l , int r){

        while(l<r){
            if(s[l] != s[r]){
                return false; 
            }

            l++;
            r--;
        }
        return true; 
    }

    void backtracking(int j, int i, vector<string>& part){

        if(i >= sc.size()){
            if(i == j){
                result.push_back(part);
            }
            return;
        }


        if(isPalindrome(sc , j , i)){
            part.push_back(sc.substr(j, i-j+1));
            backtracking(i+1, i+1,part);
            part.pop_back();
        }

        backtracking(j , i+1, part);
    }

    vector<vector<string>> partition(string s) {
        sc = s; 
        vector<string> part; 
        backtracking(0, 0, part);
        return result; 
    }
};
