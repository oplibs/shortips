#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if(strs.size()==0){
        return "";
      }
      size_t minsize = strs[0].length();
      for(auto item:strs){
        minsize = std::min(item.length(), minsize);
      }
      if(minsize==0){
        return "";
      }
      std::string ret;
      std::string comparestr = strs[0];
      for(int i = 0; i<minsize; i++){
        bool common = true;
        for(auto item:strs){
          if(item[i]!=comparestr[i]){
            common = false;
            break;
          }
        }
        if(common){
          ret.append(1, comparestr[i]);
        }else{
          break;
        }
      }
      return ret;
    }
};
