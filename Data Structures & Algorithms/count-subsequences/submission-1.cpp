class Solution {
public:

    int recur(string& s, string& t, int idofT, int idofS, vector<vector<int>>& dp){ 
        if(idofT == t.size()) return 1; 
        
        if(idofS == s.size()) return 0; 

        if(dp[idofS][idofT] != -1) return dp[idofS][idofT];

        dp[idofS][idofT] = 0; 

        if(s[idofS] == t[idofT]) {
            dp[idofS][idofT] += recur(s, t, idofT +1, idofS + 1, dp) ;
        }

        dp[idofS][idofT] += recur(s, t, idofT, idofS + 1, dp);

        return dp[idofS][idofT];


    }
    int numDistinct(string s, string t) {

        vector<vector<int>> dp( s.size() + 1, vector<int>(t.size() + 1, -1));

        return recur(s, t, 0, 0, dp);
       
        
    }
};
