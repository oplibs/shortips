#include <algorithm>

class Solution {
public:
    int jump(vector<int>& nums) {
      if(nums.size()<2){
        return 0;
      }
      vector<int> steps = vector<int>(nums.size(), nums.size());
      steps[0] = 0;
      for(int i = 0; i< nums.size(); i++){
        int stepcur = steps[i]+1;
        for(int start = 1; start <= nums[i] ; start++){
          if((start+i)>=steps.size()){
            break;
          }
          steps[start+i] = std::min(steps[start+i], stepcur);
        }
      }
      return steps[nums.size()-1];
    }
};
