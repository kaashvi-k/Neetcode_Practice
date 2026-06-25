class Solution {
public:
    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int i) {
        if(i == word.length()) return true; 

        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i]){
            return false;
        }

        board[r][c] = '#';
        bool ret = dfs(board, r +1 , c , word , i+1) ||
                    dfs(board, r -1  , c , word , i+1) ||
                    dfs(board, r , c + 1 , word , i+1) ||
                    dfs(board, r , c -1 , word , i+1);
        
        board[r][c] = word[i];
        return ret; 
        
                    
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size() , cols = board[0].size(); 
        vector<string> res; 

        for(string& word: words){
            bool flag = false; 



            for( int r = 0; r < rows; r++){
                for(int c = 0 ; c < cols; c ++){
                    if(flag) break;
                    if(board[r][c] != word[0]) continue; 
                    
                    if(dfs(board, r, c, word, 0)){
                        res.push_back(word);
                        flag = true; 
                        break;
                    }

                }
            }
        }
        return res; 
    }


};
