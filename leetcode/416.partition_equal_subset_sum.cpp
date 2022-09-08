class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2==1){
            return false;
        }
        int target=sum/2;
        //1. 最浪费存储的写法：
        /*
        //纵轴为可选item数量，横轴为了方便就是[0, target];
        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1,false));
        for(int i=0; i<nums.size(); i++){
            dp[i][0]=true;
        }
        for(int i=1; i<nums.size();i++){
            int val=nums[i];
            for(int idx=1;idx<=target;idx++){
                //目标值必须大于要用的那个值才有意义（都是正数）
                if(idx>=val){
                    dp[i][idx]=dp[i-1][idx] || dp[i-1][idx-val];
                }else{
                    //目标值如果小于，相当于当前的val不用放，直接看以前的。
                    dp[i][idx]=dp[i-1][idx];
                }
            }
        }
        return dp[nums.size()-1][target];
        */
        //2. 比较节约存储的写法：
        //纵轴为可选item数量，横轴为了方便就是[0, target];
        vector<bool> dp(target+1, false);
        //一定要初始化,至少解决idx==val的情况
        dp[0]=true;
        for(int i=1; i<nums.size();i++){
            int val=nums[i];
            //逆序检查，因为公用了空间，所以正序检查就丢掉了以前的状态。
            for(int idx=target;idx>=val;idx--){
                //目标值必须大于要用的那个值才有意义（都是正数）
                if(idx>=val){
                    // 因为只用了一维数组，所以下面这个公式有歧义，看上去没有用上一次的状态，但其实用的就是上一次的状态.
                    // 不像用多维数组的时候总有一个dp[i][val]=f(dp[i-1][target],dp[i-1][target-val])
                    dp[idx]=dp[idx] || dp[idx-val];
                }
            }
        }
        return dp[target];
    }
};
