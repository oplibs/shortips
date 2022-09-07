#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.length()<2){
        return s.length();
      }
      //注意这里的起始状态，从-1、0开始
      int start = -1;
      int end = 0;
      int ret = 1;
      std::set<char> chkset;
      while(end < s.length()){
        if(chkset.count(s[end])>0) {
          chkset.erase(s[++start]);
        } else {
          ret = std::max(ret, end - start);
          chkset.insert(s[end++]);
        }
      }
      return ret;
    }
};
