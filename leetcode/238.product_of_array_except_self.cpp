class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fromstart(nums.size(),1);
        vector<int> fromend(nums.size(),1);
        vector<int> results;
        int startcur=1;
        int endcur=1;
        for(size_t i=0; i<nums.size(); i++){
            fromstart[i] = startcur;
            if(i>0){
                startcur*=nums[i-1];
                fromstart[i] = startcur;
            }
            size_t endpos = nums.size()-1-i;
            fromend[endpos] = endcur;
            if(endpos<nums.size()-1){
                endcur*=nums[endpos+1];
                fromend[endpos] = endcur;
            }
        }
        for(size_t i=0; i<nums.size(); i++){
            results.push_back(fromstart[i]*fromend[i]);
        }
        return results;
    }
};
