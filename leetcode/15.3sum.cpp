class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if(nums.size()<3){
            return results;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            // 优化1：最小值都>0,和必然大于
            if(nums[i]>0){
                break;
            }
            // 优化2：避免数值相等的场景
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum>0){
                    end--;
                }else if(sum<0){
                    start++;
                }else{
                    vector<int> item;
                    item.push_back(nums[i]);
                    item.push_back(nums[start]);
                    item.push_back(nums[end]);
                    results.push_back(item);
                    // 优化：避免数值相等的场景
                    while(start<end && nums[start]==nums[start+1]){
                        start++;
                    }
                    // 别忘了更新啊
                    start++;
                    while(start<end && nums[end]==nums[end-1]){
                        end--;
                    }
                    end--;
                }
            }
        }
        return results;
    }
};
