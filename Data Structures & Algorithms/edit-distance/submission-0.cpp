class Solution {
public:

    vector<vector<int>> dp;

    int dfs(int i, int j, string& word1, string& word2) {

        int m = word1.size();
        int n = word2.size();

        if (i == m) return n - j;
        if (j == n) return m - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = dfs(i + 1, j + 1, word1, word2);
        }

        int del = dfs(i + 1, j, word1, word2);
        int ins = dfs(i, j + 1, word1, word2);
        int rep = dfs(i + 1, j + 1, word1, word2);

        return dp[i][j] = 1 + min({del, ins, rep});
    }

    int minDistance(string word1, string word2) {

        dp.assign(
            word1.size() + 1,
            vector<int>(word2.size() + 1, -1)
        );

        return dfs(0, 0, word1, word2);
    }
};