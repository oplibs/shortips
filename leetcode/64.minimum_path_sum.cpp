class Solution {
public:
    void backtrack(vector<vector<int>>& grid, int curm, int curn, int& cursum, int& minsum, int maxm, int maxn){
      cursum+=grid[curm][curn];
      if((curm==maxm-1) && (curn==maxn-1)){
        if(minsum<0){
          minsum=cursum;
        } else if(cursum<=minsum){
          minsum=cursum;
        }
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
};
