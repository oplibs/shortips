class Solution {
public:
    string convert(string s, int numRows) {
      //Corner case !!!
      if(numRows == 1){
        return s;
      }
      string results(s);
      int start = 0;
      int step = 2*(numRows - 1);
      vector<int> pos;
      while(start < s.length()){
        pos.push_back(start);
        start+=step;
      }
      int t = 0;
      //Not very clean
      for(int i = 0 ; i < numRows; i++) {
        vector<int> candidates;
        candidates.push_back(i);
        int next = step-i;
        if(next != i && next != step){
          candidates.push_back(next);
        }

        for(int mark = 0; mark < pos.size(); mark++) {
          for(int j = 0; j < candidates.size(); j++) {
            int where = pos[mark]+candidates[j];
            if(where < s.length()){
              results[t++]=s[where];
            }
          }
        }
      }
      return results;
    }
};
