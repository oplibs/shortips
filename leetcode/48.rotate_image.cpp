class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      size_t width=matrix.size();
      if(width == 1){
        return;
      };
      int temp;
      size_t i = 0;
      size_t j = 0;
      //  Try this for starting loop from i+1
      for(i = 0; i < width; i++){
        for(j = i+1; j < width ; j++){
          temp = matrix[i][j];
          matrix[i][j]=matrix[j][i];
          matrix[j][i] = temp;
        }
      }
      for(i = 0; i < width; i++){
        for(j = 0; j < width/2 ; j++){
          temp = matrix[i][j];
          matrix[i][j]=matrix[i][width-1-j];
          matrix[i][width-1-j] = temp;
        }
      }
      // for(i = 0; i < width; i++){
        // for(j = 0; j < width ; j++){
          // printf("%d,",matrix[i][j]);
        // }
        // printf("\n");
      // }
    }
};
