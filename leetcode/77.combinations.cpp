class Solution {
public:
    void iterate(vector<vector<int>>& results, vector<int>& item, int cur, int n, int k){
      if(item.size()==k){
        results.push_back(item);
        return;
      }
      for(int i = cur; i<=n; i++){
        item.push_back(i);
        // printf("%d-%d\n", i, item.size());
        iterate(results, item, i+1, n, k);
        item.pop_back();
        // printf("%d-%d\n", i, item.size());
        // WTF : why add the following line
        // iterate(results, item, i+1, n, k);
      }
    }

    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> results;
      vector<int> item;
      iterate(results, item, 1, n, k);
      return results;
    }
};
