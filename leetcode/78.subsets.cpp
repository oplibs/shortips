class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& item, const vector<int>& nums,int cur, int len){
      if(cur == len){
        result.push_back(item);
        return;
      }
      item.push_back(nums[cur]);
      backtrack(result, item, nums, cur+1, len);
      item.pop_back();
      backtrack(result, item, nums, cur+1, len);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      int len = nums.size();
      vector<vector<int>> results;
      vector<int> item;
      backtrack(results, item, nums, 0, len);

      return results;
    }
};
