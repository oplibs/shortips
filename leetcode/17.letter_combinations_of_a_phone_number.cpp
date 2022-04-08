class Solution {
public:
    void backtrack(map<char, vector<char>>& dict, vector<string>& result, string& item, string& digits){
      if(digits.length()==0){
        result.push_back(item);
        return;
      }
      vector<char> from = dict[digits[0]];
      for(int i = 0; i < from.size(); i++) {
        std::string substr = digits.substr(1, digits.length());
        item.append(1, from[i]);
        backtrack(dict, result, item, substr);
        item = item.substr(0, item.length()-1);
      }
    }
    vector<string> letterCombinations(string digits) {
      std::map<char, vector<char>> dict;
      dict['2']={'a','b','c'};
      dict['3']={'d','e','f'};
      dict['4']={'g','h','i'};
      dict['5']={'j','k','l'};
      dict['6']={'m','n','o'};
      dict['7']={'p','q','r', 's'};
      dict['8']={'t','u','v'};
      dict['9']={'w','x','y','z'};

      vector<string> result;
      if(digits.length()==0){
        return result;
      }
      std::string item="";
      backtrack(dict, result, item, digits);
      return result;
    }
};
