class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size()<2){
        return nums.size();
      }
      int start=0, ends=1;
      while(ends<nums.size()){
        if(nums[start]==nums[ends]){
          ends++;
        }else if(nums[start]<nums[ends]){
          nums[++start]=nums[ends++];
        }
      }
      return start+1;
    }
};
