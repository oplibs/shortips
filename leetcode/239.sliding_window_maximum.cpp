class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        vector<int> results(nums.size()-k+1);
        //queue存的可是位置
        deque<int> maxqueue;
        //1. 先初始化，少放一个，这样在正式循环中可以补充数字。[0,k-1)
        for(int i=0; i < k-1; i++){
            while(maxqueue.size()>0 && nums[maxqueue.back()]<nums[i]){
                maxqueue.pop_back();
            }
            maxqueue.push_back(i);
            //printf("pos size top: %d %d %d %d\n", i, maxqueue.size(), maxqueue.front(),nums[maxqueue.front()]);
        }
        //2. 正式循环中可以补充数字.
        //   字符串循环区间是：[k-1, n)
        //   写入位置是(i-k+1,可以从初始点推导出来)
        for(int i=k-1; i < nums.size(); i++){
            while (maxqueue.size()>0 && nums[i]>nums[maxqueue.back()]){
                maxqueue.pop_back();
            }
            maxqueue.push_back(i);
            //printf("pos size top: %d %d %d %d\n", i, maxqueue.size(), maxqueue.front(),nums[maxqueue.front()]);
            while(maxqueue.front()<=(i-k)){
                maxqueue.pop_front();
            }
            //printf("set: %d %d %d\n", i-k, maxqueue.front(),nums[maxqueue.front()]);
            results[i-k+1]=nums[maxqueue.front()];
        }

        return results;
    }
};
