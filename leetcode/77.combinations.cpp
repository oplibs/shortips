class Solution {
public:
    void dfs(vector<vector<int>>& results, vector<int>& item, vector<bool>& visited, int start, int n, int k){
        if(item.size()==k){
            results.push_back(item);
            return;
        }
        //如果不是最少两个元素构成子集，可以在start>0完成push，就包含所有自己的情况了
        if(start>n){
            return;
        }
        item.push_back(start);
        dfs(results, item, visited, start+1, n, k);
        item.pop_back();
        dfs(results, item, visited, start+1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> item;
        vector<vector<int>> results;
        vector<bool> visited(n+1,false);
        dfs(results, item, visited, 1, n, k);
        return results;
    }
};
