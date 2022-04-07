class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      if(!(matrix.size() > 0 && matrix[0].size()>0)){
        return;
      }
      int rowstatus=matrix[0][0];
      for(int n = 0; n < matrix[0].size(); n++){
        if(matrix[0][n]==0){
          rowstatus = 0;
          break;
        }
      }
      int columnstatus=matrix[0][0];
      for(int m = 0; m < matrix.size(); m++){
        if(matrix[m][0]==0){
          columnstatus = 0;
          break;
        }
      }
      for(int m = 1; m < matrix.size(); m++){
        for(int n = 1; n < matrix[0].size(); n++){
          if(matrix[m][n]==0){
            matrix[m][0] = 0;
            matrix[0][n] = 0;
          }
        }
      }
      for(int m = 1; m < matrix.size(); m++){
        for(int n = 1; n < matrix[0].size(); n++){
          if(matrix[m][0]==0 || matrix[0][n] == 0){
            matrix[m][n] = 0;
          }
        }
      }
      for(int m = 1; m < matrix.size(); m++){
        if(columnstatus==0){
          matrix[m][0] = 0;
        }
      }
      for(int n = 1; n < matrix[0].size(); n++){
        if(rowstatus ==0){
          matrix[0][n] = 0;
        }
      }
      if(columnstatus == 0 || rowstatus == 0) {
        matrix[0][0] = 0;
      }
    }
};
