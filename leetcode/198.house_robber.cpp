#include <algorithm>
class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size()==1){
        return nums[0];
      }else if(nums.size()==2){
        return nums[0]>nums[1]?nums[0]:nums[1];
      }
      int amount = 0;
      for(int cur=1; cur < nums.size(); cur++){
        nums[cur] = std::max(amount+nums[cur], nums[cur-1]);
        amount = nums[cur-1];
      }
      return nums[nums.size()-1];
    }
};
