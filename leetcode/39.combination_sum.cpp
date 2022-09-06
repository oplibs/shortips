class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& results, vector<int> item, int curstep, int target){
        if(target==0){
            results.push_back(item);
            return;
        }
        // 循环从curstep开始，防止重复选择在数组中靠前的元素
        for(int i=curstep; i<candidates.size(); i++){
            if(target-candidates[i]<0){
                continue;
            }
            item.push_back(candidates[i]);
            // 下面从i开始，意味着candidates[i]可以选择多次。
            dfs(candidates,results,item, i, target-candidates[i]);
            item.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> item;
        dfs(candidates, results, item, 0, target);
        return results;
    }
};
