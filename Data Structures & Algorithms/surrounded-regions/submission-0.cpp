/*
approach 
from o's that are on the edge, do dfs and mark all the o's as -1; 
then convert everything that isnt a -1 to X
then convert all -1's to o's
*/

class Solution {
public:

    vector<int> ro = {1, -1, 0, 0};
    vector<int> co = {0 , 0 , -1, 1};

    void dfs(vector<vector<char>>&board , int r , int c){

        stack<pair<int, int>> st; 
        st.push({r,c});

        while(!st.empty()){
            int rc = st.top().first; 
            int cc = st.top().second;
            board[r][c] = '#';
            st.pop();

            for(int i = 0 ; i < 4; i++){
                int rn = rc + ro[i]; 
                int cn = cc + co[i];

                if(rn >= 0 && rn < board.size() &&
                    cn >= 0 && cn < board[0].size() &&
                    board[rn][cn] == 'O') {
                        st.push({rn , cn});
                        board[rn][cn] = '#';
                    }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        

        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){

                if( (i == 0 || i == board.size()-1 )&& board[i][j] == 'O'){
                    dfs( board, i , j);
                    board[i][j] = '#';
                }


                if( (j == 0 || j == board[0].size() - 1 )&& board[i][j] == 'O'){
                    dfs(board, i , j);
                    board[i][j] = '#';
                }
            }
        }

        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size(); j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
