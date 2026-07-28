class Solution {
public:
    bool recur(string& s1, string& s2, string&s3, int si, int sj, vector<vector<int>>& dp){
        if(si == s1.size() && sj == s2.size()) return true;

        if(dp[si][sj] != -1) return dp[si][sj];

        bool ans = false;

        if (si < s1.size() && s1[si] == s3[sj + si])
            ans |= recur(s1, s2, s3, si + 1, sj , dp);

        if (sj < s2.size() && s2[sj] == s3[sj + si])
            ans |= recur(s1, s2, s3, si , sj + 1, dp);

        return dp[si][sj] = ans;



    }
    bool isInterleave(string s1, string s2, string s3) {

        if(s3 == "") return true; 
        if(s1.size() + s2.size() != s3.size()) return false; 


        vector<vector<int>> dp(s1.size() + 1 , vector<int> (s2.size() + 1, -1));

        return recur(s1, s2, s3, 0, 0, dp);
        
    }
};
