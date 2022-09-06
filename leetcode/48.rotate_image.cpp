class Solution {
  public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose
    for (int i = 0; i < n; i++) {
      // Transpose : j<i
      for (int j = 0; j < i; j++) {
				if (i != j) {
				  int temp = matrix[i][j];
				  matrix[i][j] = matrix[j][i];
				  matrix[j][i] = temp;
				}
      }
    }
    // Mirror
    for (int i = 0; i < n; i++) {
      // Mirror : j<n/2
      for (int j = 0; j < n / 2; j++) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][n - 1 - j];
				matrix[i][n - 1 - j] = temp;
      }
    }
    return;
  }
};
