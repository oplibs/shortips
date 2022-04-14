class Solution {
public:
    int uniquePaths(int m, int n) {
      if(m < 2 || n < 2) {
        return 1;
      }
      vector<int> mnt(n, 1);
      for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
          mnt[j]=mnt[j-1] + mnt[j];
        }
      }
      return mnt[n-1];
    }
};
