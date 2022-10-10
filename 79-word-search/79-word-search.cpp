class Solution {
public:

    vector<vector<int>> dir{{0,1}, {1,0}, {-1,0}, {0,-1}};

    bool exist(vector<vector<char>>& board, string word, int crow, int ccol, int sindex, vector<vector<int>> &vi) {
        
        int len_word = word.size();
        int nrow = board.size();
        int ncol = board[0].size();
        
        // if(sindex == len_word-1 && word[sindex]==board[crow][ccol])
        //     return true;
        
        if(sindex >= len_word)
            return true;
        
        if(crow >= nrow || ccol >= ncol || crow < 0 || ccol < 0 || sindex < 0 || vi[crow][ccol] == 1 || (board[crow][ccol] != word[sindex]))
            return false;
        // cout<<crow<<" "<<ccol<<" "<<sindex<<" "<<endl;

        vi[crow][ccol] = 1;
        for(int i=0;i<4;i++){
            bool temp = exist(board, word, crow+dir[i][0], ccol+dir[i][1], sindex+1, vi);
            if(temp == true){
                return true;
            }
        }
        vi[crow][ccol] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len_word = word.size();
        int nrow = board.size();
        int ncol = board[0].size();

        if(len_word == 0){
            return true;
        }
        vector<vector<int>> vi(nrow, vector<int> (ncol, 0));
        
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
               if(board[i][j] == word[0]){
                   bool temp = exist(board, word, i, j, 0, vi);
                   if(temp == true){
                    return true;
                   }                
               }
 
            }
        }

        return false;
    }
};