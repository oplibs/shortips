class Solution {
  public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }
    if (sum % 2 == 1) {
      return false;
    }
    int target = sum / 2;
    //纵轴为可选item数量，横轴为了方便就是[0, target];
    vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
    for (int i = 0; i < nums.size(); i++) {
      dp[i][0] = true;
    }
    for (int i = 1; i < nums.size(); i++) {
      int val = nums[i];
      for (int idx = 1; idx <= target; idx++) {
				//目标值必须大于要用的那个值才有意义（都是正数）
				if (idx >= val) {
				  dp[i][idx] = dp[i - 1][idx] || dp[i - 1][idx - val];
				} else {
				  //目标值如果小于，相当于当前的val不用放，直接看以前的。
				  dp[i][idx] = dp[i - 1][idx];
				}
      }
    }
    return dp[nums.size() - 1][target];
  }
};
