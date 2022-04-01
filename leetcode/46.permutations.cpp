class Solution {
public:
    void backtrack(vector<vector<int>>& results, vector<int>& item, vector<int>& nums){
      if(nums.size()==0){
        results.push_back(item);
        return;
      }
      for(int pos=0;pos < nums.size(); pos++){
        int val = nums[pos];
        nums.erase(nums.begin()+pos);
        item.push_back(val);
        backtrack(results, item, nums);
        item.pop_back();
        nums.insert(nums.begin()+pos, val);
      }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> results;
      vector<int> item;
      backtrack(results, item, nums);
      return results;
    }
};
