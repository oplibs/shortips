class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      int row[9][9]={0};
      int column[9][9]={0};
      int block[3][3][9]={0};
      for(size_t i = 0; i < 9; i++){
        for(size_t j = 0; j < 9; j++){
          char val = board[i][j];
          if(val != '.'){
            int idx = val-'1';
            row[i][idx]++;
            column[j][idx]++;
            block[i/3][j/3][idx]++;
            if(row[i][idx]>1 || column[j][idx] > 1 || block[i/3][j/3][idx]>1){
              return false;
            }
          }
        }
      }
      return true;
    }
};
