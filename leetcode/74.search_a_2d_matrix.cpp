class Solution {
public:
    int getval(const vector<vector<int>>& matrix, int height, int width, int pos){
      int posy=pos / width;
      int posx=pos % width;
      return matrix[posy][posx];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int height = matrix.size();
      if(height==0){
        return false;
      }
      int width = matrix[0].size();
      if(width==0){
        return false;
      }
      if(width==1 && height==1){
        return matrix[0][0] == target;
      }
      int start=0;
      int end=width*height - 1;
      while(start <= end){
        int mid=(start + end)/2;
        int val = getval(matrix, height, width, mid);
        // printf("%d @ %d\n",val, mid);
        if(val == target){
          return true;
        }else if(val > target){
          //BinarySerch 避免漏数字
          //comment:not minus 1
          end = mid-1;
        }else {
          //comment:need plus 1
          start = mid+1;
        }
      }
      return false;
    }
};
