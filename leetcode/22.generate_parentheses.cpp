class Solution {
public:
    void backtrack(int length, int& cur, string& item,int& used, int& depth, vector<string>& result){
      if(cur==length){
        result.push_back(item);
        return;
      }
      if(used<length/2){
        item[cur++]='(';
        used++;
        depth++;
        backtrack(length, cur, item,used, depth, result);
        used--;
        depth--;
        cur--;
      }
      if(depth>0){
        item[cur++]=')';
        depth--;
        backtrack(length, cur, item,used, depth, result);
        depth++;
        cur--;
      }
    }

    vector<string> generateParenthesis(int n) {
      int length=2*n;
      string item = string(length, ' ');
      int cur = 0;
      int used = 0;
      int depth = 0;
      vector<string> result;
      backtrack(length, cur, item, used, depth, result);
      return result;
    }
};
