class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur=0;
        int end=0;
        // 状态初始化/同时cur<nums.size()要写在前面
        while(cur<nums.size()&&nums[cur]==0){
            cur++;
        }
        //printf("%d\n",cur);
        while(cur<nums.size()){
            if(nums[cur]!=0){
                if(cur!=end){
                    nums[end]=nums[cur];
                }
                end++;
            }
            cur++;
        }
        while(end<nums.size()){
            nums[end++]=0;
        }
    }
};
