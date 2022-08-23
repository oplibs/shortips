class Solution {
public:
    int longestValidParentheses(string s) {
        size_t len = s.length();
        if(len<2){
            return 0;
        }
        vector<int> count(s.length(), 0);
        int maxlen=0;
        if(s[0]=='(' && s[1]==')'){
            count[1] = 2;
            maxlen = 2;
        }

        for(size_t pos = 2; pos < s.length(); pos++){
            if(s[pos]=='('){
                count[pos]=0;
            }else if(s[pos]==')' && s[pos-1]=='('){
                count[pos]=2;
                if(pos-2>=0){
                    count[pos]+=count[pos-2];
                }
            }else{
                int frompos = pos-1-count[pos-1];
                if(frompos>=0 && s[frompos]=='('){
                    count[pos]=count[pos-1]+2;
                    if(frompos-1>=0){
                        count[pos]+=count[frompos-1];
                    }
                }
            }
            maxlen = std::max(maxlen, count[pos]);
        }
        return maxlen;
    }
};


