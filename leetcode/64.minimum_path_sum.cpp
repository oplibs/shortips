#include <algorithm>

class Solution {
  public:
  /*
    void backtrack(vector<vector<int>>& grid, int curm, int curn, int& cursum,
    int& minsum, int maxm, int maxn){ cursum+=grid[curm][curn];
      if((curm==maxm-1) && (curn==maxn-1)){
        if(minsum<0 || cursum<minsum){
          minsum=cursum;
        }
      }else if (cursum>=minsum && minsum>0){
      }else{
        if(curm<maxm-1){
          backtrack(grid, curm+1, curn, cursum, minsum, maxm, maxn);
        }
        if(curn<maxn-1){
          backtrack(grid, curm, curn+1, cursum, minsum, maxm, maxn);
        }
      }
      cursum-=grid[curm][curn];
    }
    int minPathSum(vector<vector<int>>& grid) {
      int M = grid.size();
      if(M==0){
        return 0;
      }
      int N = grid[0].size();
      if(N==0){
        return 0;
      }
      int cursum = 0;
      int minsum = -1;
      int curm = 0;
      int curn = 0;
      backtrack(grid, curm, curn, cursum, minsum, M, N);
      return minsum;
    }
    */
  int minPathSum(vector<vector<int>>& grid) {
    int M = grid.size();
    if (M == 0) {
      return 0;
    }
    int N = grid[0].size();
    if (N == 0) {
      return 0;
    }
    for (int n = 1; n < N; n++) {
      grid[0][n] = grid[0][n - 1] + grid[0][n];
    }
    for (int m = 1; m < M; m++) {
      grid[m][0] = grid[m - 1][0] + grid[m][0];
    }
    for (int m = 1; m < M; m++) {
      for (int n = 1; n < N; n++) {
        grid[m][n] = std::min(grid[m - 1][n], grid[m][n-1])+grid[m][n];
      }
    }
    return grid[M-1][N-1];
  }
};
