class Solution {
public:
    bool isValid(string s) {
      if(s.length()%2==1){
        return false;
      }
      std::stack<char> sta;
      for(int pos=0; pos < s.length(); pos++){
        switch(s[pos]){
          case '(':
          case '[':
          case '{':
            sta.push(s[pos]);
            break;
          case ')':
            if(sta.size()>0 && sta.top()=='('){
              sta.pop();
            } else {
              return false;
            }
            break;
          case ']':
            if(sta.size()>0 && sta.top()=='['){
              sta.pop();
            } else {
              return false;
            }
            break;
          case '}':
            if(sta.size()>0 && sta.top()=='{'){
              sta.pop();
            } else {
              return false;
            }
            break;
        }
      }
      return sta.size()==0;
    }
};
