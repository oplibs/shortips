class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::vector<int> ret;
      std::map<int, int> dict;
      size_t i;
      for(i=0; i<nums.size(); i++){
        dict[nums[i]]=i;
      }
      for(i=0; i<nums.size(); i++){
        int left = target-nums[i];
        map<int, int>::iterator it = dict.find(left);
        if(it!=dict.end() && it->second!=i){
          ret.push_back(i);
          ret.push_back(it->second);
          return ret;
        }
      }
      return ret;
    }
};
